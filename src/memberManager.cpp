#include "memberManager.h"

void addMember(map<string, Member> &members) {
    // Generate new 9-digit ID
    string id;
    if (members.empty()) {
        id = "000000001";
    } else {
        long long maxID = 0;
        for (auto const &[key, _] : members) {
            maxID = max(maxID, stoll(key));
        }
        ostringstream oss;
        oss << setw(9) << setfill('0') << (maxID + 1);
        id = oss.str();
    }
    cout << "Assigned Member ID: " << id << "\n";

    // Collect the rest of the fields
    string name = getValidatedInput(2, 25, "letters", false, "Name");
    string street = getValidatedInput(2, 25, "all", false, "Street");
    string city = getValidatedInput(2, 14, "letters", false, "City");
    string state = getValidatedInput(2, 2, "letters", true, "State");
    string zip = getValidatedInput(5, 5, "numbers", false, "Zip code");

    // 3) Build Member object
    Member m;
    m.setID(id);
    m.setName(name);
    m.setStreet(street);
    m.setCity(city);
    m.setState(state);
    m.setZip(zip);
    m.setSuspended(false);

    // 4) Store in map & CSV
    members[id] = m;
    ofstream out("data/members.csv", ios::app);
    // write header if file was just created/empty

    out << id << ',' << name << ',' << street << ',' << city << ',' << state
        << ',' << zip << ",Active\n";

    cout << "Member added successfully.\n";
}

void loadMembersFromCSV(const string &filename, map<string, Member> &members) {
    ifstream file(filename);
    if (!file.is_open()) {
        ofstream out("data/members.csv", ios::app);

        // write header if file was just created/empty
        if (out.tellp() == 0) {
            out << "id,name,street,city,state,zip,suspended\n";
        }
        return;
    }

    string line;
    // skip header
    getline(file, line);

    while (getline(file, line)) {
        stringstream ss(line);
        string id, name, street, city, state, zip;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, street, ',');
        getline(ss, city, ',');
        getline(ss, state, ',');
        getline(ss, zip, ',');

        Member m;
        m.setID(id);
        m.setName(name);
        m.setStreet(street);
        m.setCity(city);
        m.setState(state);
        m.setZip(zip);
        // suspended defaults to false

        members[id] = m;
    }
}

void validateMember(map<string, Member> &members) {

    string id = getValidatedInput(9, 9, "numbers", false, "id");
    auto it = members.find(id);
    if (it != members.end()) {

        const Member &m = it->second;
        cout << "Found member: " << m.getName() << "\n";
    } else {
        cout << "Member not found\n";
    }
}

void showAllMembers(const map<string, Member> &members) {
    cout << endl;
    if (members.empty()) {
        cout << "No members found.\n";
        return;
    }
    for (const auto &[id, m] : members) {
        cout << "ID:         " << id << '\n'
             << "Name:       " << m.getName() << '\n'
             << "Street:     " << m.getStreet() << '\n'
             << "City:       " << m.getCity() << '\n'
             << "State:      " << m.getState() << '\n'
             << "ZIP:        " << m.getZip() << '\n'
             << "Suspended:  " << (m.isSuspended() ? "Suspended" : "Active")
             << '\n'
             << "--------------------------------\n";
    }
}

void changeMemberAccess(map<string, Member> &members) {
    string id = getValidatedInput(9, 9, "numbers", false, "ID");
    auto it = members.find(id);
    if (it == members.end()) {
        cout << "Member " << id << " not found.\n";
        return;
    }
    if (it->second.isSuspended()) {
        it->second.setSuspended(false);
        cout << "Member " << id << " active.\n";
    } else {
        it->second.setSuspended(true);
        cout << "Member " << id << " suspended.\n";
    }
    rebuildCSV(members);
}

void updateMemberInfo(map<string, Member> &members, int choice, Member &m) {
    if (choice == 1) {
        string name = getValidatedInput(2, 25, "letters", false, "Name");
        m.setName(name);
        cout << "Name updated.\n";
    } else if (choice == 2) {
        string street = getValidatedInput(2, 25, "all", false, "Street");
        m.setStreet(street);
        cout << "Street updated.\n";
    } else if (choice == 3) {
        string city = getValidatedInput(2, 14, "letters", false, "City");
        m.setCity(city);
        cout << "City updated.\n";
    } else if (choice == 4) {
        string state = getValidatedInput(2, 2, "letters", true, "State");
        m.setState(state);
        cout << "State updated.\n";
    } else if (choice == 5) {
        string zip = getValidatedInput(5, 5, "numbers", false, "Zip code");
        m.setZip(zip);
        cout << "ZIP updated.\n";
    } else if (choice == 6) {
        string name = getValidatedInput(2, 25, "letters", false, "Name");
        string street = getValidatedInput(2, 25, "all", false, "Street");
        string city = getValidatedInput(2, 14, "letters", false, "City");
        string state = getValidatedInput(2, 2, "letters", true, "State");
        string zip = getValidatedInput(5, 5, "numbers", false, "Zip code");

        m.setName(name);
        m.setStreet(street);
        m.setCity(city);
        m.setState(state);
        m.setZip(zip);

        cout << "All fields updated.\n";
    }
    // persist changes to CSV
    rebuildCSV(members);
}

void deleteMember(map<string, Member> &members) {
    cout << "Delete Member\n";
    string id = getValidatedInput(9, 9, "numbers", false, "ID");
    auto it = members.find(id);
    if (it == members.end()) {
        cout << "Member not found\n";
        return;
    }
    members.erase(it);
    cout << "Member deleted successfully.\n";
    rebuildCSV(members);
}

void rebuildCSV(const map<string, Member> &members) {
    ofstream out("data/members.csv", ios::trunc);
    // write header
    out << "id,name,street,city,state,zip,suspended\n";
    // write each record
    for (auto const &[id, m] : members) {
        out << id << ',' << m.getName() << ',' << m.getStreet() << ','
            << m.getCity() << ',' << m.getState() << ',' << m.getZip() << ','
            << (m.isSuspended() ? "Suspended" : "Active") << '\n';
    }
}