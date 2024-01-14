#include <iostream>
#include <map>
#include <list>

class Graph {
private:
    std::map<int, std::list<int> > phoneGraph;

public:
    void addVertex(int phoneNumber) {
        phoneGraph[phoneNumber]; // Menambahkan nomor telepon baru ke dalam graph
    }

    void addEdge(int from, int to) {
        phoneGraph[from].push_back(to);
        phoneGraph[to].push_back(from);
    }

    void displayVertices() {
        std::cout << "Daftar Kontak:\n";
        for (std::map<int, std::list<int> >::const_iterator it = phoneGraph.begin(); it != phoneGraph.end(); ++it) {
            std::cout << it->first << "\n";
        }
    }

    void displayEdges(int phoneNumber) {
        std::cout << "Hubungan untuk nomor telepon " << phoneNumber << ":\n";
        std::map<int, std::list<int> >::const_iterator it = phoneGraph.find(phoneNumber);
        if (it != phoneGraph.end()) {
            const std::list<int>& contacts = it->second;
            for (std::list<int>::const_iterator contactIt = contacts.begin(); contactIt != contacts.end(); ++contactIt) {
                std::cout << *contactIt << " ";
            }
        }
        std::cout << "\n";
    }
};

int main() {
    Graph phoneGraph;

    phoneGraph.addVertex(123);
    phoneGraph.addVertex(456);
    phoneGraph.addVertex(789);

    phoneGraph.addEdge(123, 456);
    phoneGraph.addEdge(456, 789);

    phoneGraph.displayVertices();

    phoneGraph.displayEdges(123);
    phoneGraph.displayEdges(456);

    return 0;
}
