//
//  main.cpp
//  HomecloudFixer
//
//  Created by Emil Panecki on 31/01/2021.
//  Copyright © 2021 NintySwinty. All rights reserved.
//

#include <SFML/Network.hpp>
#include <iostream>
#include <algorithm>
#include <thread>

using namespace std;

// Varables

std::string command;
bool online = false;

// Network functions

void tcpServer() {
    sf::TcpListener listener;
    sf::TcpSocket socket;
    
    sf::Packet packet;
    std::string string;
    
    if(listener.listen(50153) != sf::Socket::Done) {
        cout << "nasłuchuję" << endl;
    } else { cout << "Err-s-1" << endl; }
    
    if(listener.accept(socket) != sf::Socket::Done) {
        cout << "połączono" << endl;
    } else { cout << "Err-s-2" << endl; }
    
    for(;;) {
        socket.receive(packet);
        packet >> string;
        packet.clear();
        system(string.c_str());
    }
    
}

void ftpConnection() {
    // Jutro
}

// Program functions

void help() {
    system("clear");
        
    cout << "Twórca: Emil Panecki\n"
    "Wersja: 31-1-2021\n"
    "Napraw komendy: pobiera i konfiguruje od nowa komendy\n"
    "Ratunek TCP: Gdy nie można sie juz połączyć w żaden sposób jest to ostatnia deska ratunku ( potrzebuejsz do tego klienta )\n"
    "Odtworzenie FTP: Pobieranie plików systemowych dla Ubuntu 16.04 ( zalecam pobrać odrazu na starcie - łatwiejsze naprawianie za pomocą Ratunek TCP )\n"
    "\n\nNapisz OK by przejść do menu"
    << endl;
        
    getline(cin, command);
    transform(command.begin(), command.end(), command.begin(), ::tolower);
        
    if(command == "ok"){
        return;
    } else { system("clear"); cout << "Err: zła komenda" << endl; }
}

void fixCommands() {
    system("sudo apt-get --reinstall install coreutils -y");
}

void emergencyTcp() {
    system("clear");
    
    cout << "Czy chcesz włączyć pomoc TCP? ( Tak / Nie )\n" << endl;
    
    if(command == "tak"){
        online = true;
    } else if(command == "nie"){
        online = false;
    } else { system("clear"); cout << "Err: zła komenda" << endl; }
}

void recorveryFtp() {
    sf::Ftp ftp;
    
    ftp.connect("server.ip", 21, sf::seconds(5));
    ftp.login("login", "password");
    
    sf::Ftp::Response response = ftp.changeDirectory("bin");
    if(response.isOk()) {
        cout << "Stworzono" << endl;
    }
    
    sf::Ftp::ListingResponse help = ftp.getDirectoryListing();
    if(response.isOk()) {
        const std::vector<std::string>& listing = help.getListing();
        for (std::vector<std::string>::const_iterator it = listing.begin(); it != listing.end(); ++it) {
                std::cout << "- " << *it << std::endl;
                ftp.download(*it, "xxx", sf::Ftp::Binary);
        }
        
    } else { cout << "Połączenie nie udane" << endl; }
}

void mainLoop() {
    for(;;){
    
        system("clear");
    
        cout << " -- Zespoł szkół nr. 42 imienia Jana Karskiego w Warszawie -- \n" << endl;
    
        cout <<
        " Pomoc                 |"
        "\n-----------------------|"
        "\n Napraw komendy        |"
        "\n-----------------------|"
        "\n Ratunek TCP           | // Praca w toku"
        "\n-----------------------|"
        "\n Odtworzenie FTP       | // Praca w toku"
        "\n-----------------------|"
        "\n Wyjdź                 |"
        "\n-----------------------|"
        "\n\n"
        "By zadać pytanie napisz na: panecki@nerdownia24.pl\n"
        << endl;
    
        getline(cin, command);
    
        transform(command.begin(), command.end(), command.begin(), ::tolower);
        
        if(command == "pomoc") {
            help();
        } else if(command == "napraw komendy") {
            fixCommands();
        } else if(command == "ratunek tcp") {
            emergencyTcp();
        } else if(command == "odtworzenie ftp") {
            recorveryFtp();
        } else if(command == "wyjdź") {
            break;
        }
        
    }
}

int main(){
    
    std::thread mainThread(mainLoop);
    std::thread networkThread(tcpServer);
    
    mainThread.join();
    if( online ) {
        networkThread.join();
    } else { networkThread.detach(); }
    
    return 0;
    
}
