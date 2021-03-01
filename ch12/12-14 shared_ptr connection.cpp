#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <utility>
#include <memory>

using namespace std;

struct connection {
    string ip;
    int port;
    connection(string ip_, int port_):
        ip(ip_), port(port_) {}
};

struct destination {
    string ip;
    int port;
    destination(string ip_, int port_):
        ip(ip_), port(port_) {}
};

connection connect(destination * p_dest) {
    shared_ptr<connection> p_conn(new connection(p_dest->ip, p_dest->port));
    cout << "Creating connection(" << p_conn.use_count() << ")" << endl;
    return *p_conn;
}

void disconnect(connection p_conn) {
    cout << "connection close(" << p_conn.ip << ":" << p_conn.port << ")" << endl;
}

void end_connection(connection *p_conn) {
    disconnect(*p_conn);
}

void f(destination &d) {
    connection conn = connect(&d);
    shared_ptr<connection> p(&conn, end_connection);
    cout << "connecting now(" << p.use_count() << ")" << endl;
}

int main() {
    destination dest("1.2.3.4", 56);
    f(dest);

    return 0;
}