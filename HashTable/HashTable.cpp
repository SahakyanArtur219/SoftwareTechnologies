#include <iostream>
#include <list>
#include <cstring>
using namespace std;

// Hashtable to implement

class HashTable {
private:
	static const int hashGroup = 10;
	list<pair<int, string>> table[hashGroup];
public:
	bool isEmpty() const;
	int hashFunction(int key);
	void insertItem(int key, string vaule);
	void removeItem(int key);
	string searchTable(int key);
	void printTable();
};

bool HashTable::isEmpty()const {
	int sum{};
	for (int i{}; i < hashGroup; i++) {
		sum += table[i].size();
	}

	if (!sum) {
		return true;
	}
	return false;
}

int HashTable::hashFunction(int key) {
	return key % hashGroup; // Key: 905, in return functioon will split out 5
}

void HashTable::insertItem(int key, string value) {
	int hashValue = hashFunction(key);
	auto& cell = table[hashValue];
	auto bItr = begin(cell);
	bool keyExists = false;
	for (; bItr != end(cell); bItr++) {
		if (bItr->first == key) {
			keyExists = true;
			bItr->second = value;
			cout << "[WARNING] Key exist. Value replaced." << endl;
			break;
		}
	}


	if (!keyExists) {
		cell.emplace_back(key, value);
	}

	return;
}

void HashTable::removeItem(int key) {
	int hashValue = hashFunction(key);
	auto& cell = table[hashValue];
	auto bItr = begin(cell);
	bool keyExists = false;
	for (; bItr != end(cell); bItr++) {
		if (bItr->first == key) {
			keyExists = true;
			bItr = cell.erase(bItr);
			cout << "[INFO] Item removed." << endl;
			break;
		}
	}

	if (!keyExists) {
		cout << "[WARNING] Key not found. Pair not removed" << endl;
	}

	return;
}


void HashTable::printTable() {
	for (int i{}; i < hashGroup; i++) {
		if (table[i].size() == 0) continue;
			
		auto bItr = table[i].begin();
		for (; bItr != table[i].end(); bItr++) {
			cout << "[INFO] kay: " << bItr->first << " Value: " << bItr->second << endl;
		}	
	}
	return;
}

int main() {
	HashTable HT;

	if (HT.isEmpty()) {
		cout << "Correct answer. Good job.";
	}
	else {
		cout << "We need to check out code!";
	}

	HT.insertItem(701, "Jim");
	HT.insertItem(809, "Jony");
	HT.insertItem(805, "Bob");
	HT.insertItem(904, "Alisa");
	HT.insertItem(903, "Jim");
	HT.insertItem(905, "Jim");
	HT.insertItem(105, "Jim");


	HT.printTable();

	HT.removeItem(701);
	HT.removeItem(999);

	if (HT.isEmpty()) {
		cout << "We need to check code1";
	}
	else{
		cout << " Everythign is good";
	}

}



