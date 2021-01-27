//
//  main.cpp
//  HomecloudFixer
//
//  Created by NintySwinty on 21/04/2020.
//  Copyright © 2020 NintySwinty. All rights reserved.
//

#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]){

    std::string lang;
    std::fstream LangFile;
    
    std::string command;

    cout << "v0.1" << endl;
    system("clear");
    
    std::ofstream oLangFile;
    LangFile.open("Language.txt", ios::in);
    if( LangFile.good() == true ){
        while( std::getline( LangFile, lang ) )
        LangFile.close();
    } else {

        cout << "Choose language (Polski/Pусский/Español/English/Deutsch) " << endl;
        cin >> lang;
    
        transform(lang.begin(), lang.end(), lang.begin(), ::tolower);

        std::ifstream iLangFile;
        LangFile.open("Language.txt", ios::out);
        if( LangFile.good() == true ){
            LangFile << lang;
            LangFile.close();
        }
        
        cout << "Run program again" << endl;
        
        return 0;
        
    }
    
    cout << "Run this program as admin" << endl;
    
    if(lang == "polski"){
        
        for(;;){
        
            system("clear");
        
            cout << " -- Zespoł szkół nr. 42 imienia Jana Karskiego w Warszawie -- \n" << endl;
        
            cout << " Napraw komendy        |\n-----------------------|\n Zainstaluj WordPress |\n-----------------------|\n Zainstaluj PHPmyAdmin |\n-----------------------|\n Wyjdź                 |\n-----------------------|" << endl;
        
            getline(cin, command);
        
            transform(command.begin(), command.end(), command.begin(), ::tolower);
            
            if(command == "napraw komendy"){
                system("sudo apt-get --reinstall install coreutils -y");
            } else if(command == "zainstaluj wordpress") {
                system("sudo apt update -y && sudo apt install wordpress php libapache2-mod-php mysql-server php-mysql -y && echo 'Poradnik do konfiguracji: https://ubuntu.com/tutorials/install-and-configure-wordpress#3-configure-apache-for-wordpress'");
            } else if(command == "zainstaluj wordpress") {
                system("sudo apt install phpmyadmin php-mbstring php-gettext -y && sudo phpenmod mbstring -y && sudo systemctl restart apache2 -y && 'Poradnik do konfiguracji: https://www.digitalocean.com/community/tutorials/how-to-install-and-secure-phpmyadmin-on-ubuntu-18-04'");
            } else if( command == "wyjdź" ){
                return 0;
            }
            
        }
        
    } else if(lang == "pусский"){
        
        cout << " -- Школьный комплекс № 42 имени Яна Карского в Варшаве -- \n" << endl;
        
        system("clear");
        
        //Fix kernal
        
        //Install wordpress
        
        //Install phpmyadmin
        
    } else if(lang == "español"){
        
        cout << " -- Complejo escolar no. 42 nombrados después de Jan Karski en Varsovia -- \n" << endl;
        
        system("clear");
        
        //Fix kernal
        
        //Install wordpress
        
        //Install phpmyadmin
        
    } else if(lang == "english"){
        
        system("clear");
        
        cout << " -- School complex no. 42 named after Jana Karskiego in Warsaw -- \n" << endl;
        
        cout << " Fix kernel         |\n--------------------|\n Install wordpress  |\n--------------------|\n Install PHPmyAdmin |\n--------------------|\n Exit               |\n--------------------|" << endl;
        
        //Fix kernal
        
        //Install wordpress
        
        //Install phpmyadmin
        
    } else if(lang == "deutsch"){
        
        cout << " -- Schulkomplex Nr. 42 benannt nach Jan Karski in Warschau -- \n" << endl;
        
        system("clear");
        
        //Fix kernal
        
        //Install wordpress
        
        //Install phpmyadmin
        
    }
    
    return 0;

}