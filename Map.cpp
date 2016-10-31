// Implementation for class Map
#include "Map.h"
#include <thread>
#include <chrono>
#include <iostream>
#include <cstdlib>
using namespace std;

Map::Map()
{
  player = '1';

}// Map constructor

Map::Map(char player)
{
  this->player = player;
} // overloader constructor

void Map::displayBoard()
{
  cout << "\n" << endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(150));
  cout << "       7:::7" <<"                                                                :::::\n";
  std::this_thread::sleep_for(std::chrono::milliseconds(150));
  cout << "       7:::777:::77:::77             " <<"                                      :::::\n";
  std::this_thread::sleep_for(std::chrono::milliseconds(150));
  cout << "      7:::?7+777:::777::7I7?7      7777" <<"              :::    ::           ::::::: :\n";
  std::this_thread::sleep_for(std::chrono::milliseconds(150));
  cout << "     ?7777:::77:77:::77:::7I77    77?77" <<"        ::::+:::::  :     :::  :::::::::: ::\n";
  std::this_thread::sleep_for(std::chrono::milliseconds(150));
  cout << "     77:::7?7777:::77:77:::7 77 7777" <<"        ::::::::::::::: :::::::::::::::::::  ::\n";
  std::this_thread::sleep_for(std::chrono::milliseconds(150));
  cout << "     I777:::777:77:::777::777:::77+?" <<"         :::::::::::::::: :::::::::::::::::\n";
  std::this_thread::sleep_for(std::chrono::milliseconds(150));
  cout << "     777:::77::777:::7+77:77+??7::7" <<"          ::::++:+::::::::::::::::::::::::\n";
  std::this_thread::sleep_for(std::chrono::milliseconds(150));
  cout << "      777:::77::77+I777+777?777?7777" <<"           ::+::++::::::::::::::::::::::::  :\n";
  std::this_thread::sleep_for(std::chrono::milliseconds(150));
  cout << "        77:::777:::7777777I7+?77777" <<"           :::::::::::::::::::::::::::::::::::\n";
  std::this_thread::sleep_for(std::chrono::milliseconds(150));
  cout << "          ?77+77::77:7777:::77:77" <<"            :::::::::::::::::::::::::::::::::::\n";
  std::this_thread::sleep_for(std::chrono::milliseconds(150));
  cout << "                7777:::777:::777" <<"             ::  ::::::::::::::::::::::::      :\n";
  std::this_thread::sleep_for(std::chrono::milliseconds(150));
  cout << "                7I 7:::+ 777    7" <<"                ::::::::::::::     :::        :\n";
  std::this_thread::sleep_for(std::chrono::milliseconds(150));
  cout << "                  7I          I7" <<"               ::::::::::::::\n";
  std::this_thread::sleep_for(std::chrono::milliseconds(150));
  cout << "                                                   :::::::::\n";
  std::this_thread::sleep_for(std::chrono::milliseconds(150));
  cout << "                                                   :::::::\n";
  std::this_thread::sleep_for(std::chrono::milliseconds(150));
  cout << "\n\t      UNITED STATES                               SOVIET UNION\n" << endl;
}// end displayBoard

void Map::displayCountry(char player)
{
  if(player == '1') // If they want to be the US
  {
    cout << "\n" << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "\033[1;31m       7:::7\033[0m" <<"                                                                :::::\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "\033[1;31m       7:::777:::77:::77             77\033[0m" <<"                                      :::::\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "\033[1;31m       7:::?7+777:::777::7I7?7      7777\033[0m" <<"              :::    ::           ::::::: :\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "\033[1;31m     ?7777:::77:77:::77:::7I77    77?77\033[0m" <<"        ::::+:::::  :     :::  :::::::::: ::\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "\033[1;31m     77:::7?7777:::77:77:::7 77 7777+\033[0m" <<"        ::::::::::::::: :::::::::::::::::::  ::\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "\033[1;31m     I777:::777:77:::777::777:::77+?\033[0m" <<"         :::::::::::::::: :::::::::::::::::\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "\033[1;31m      777:::77::777:::7+77:77+??7::7\033[0m" <<"          ::::++:+::::::::::::::::::::::::\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "\033[1;31m      777:::77::77+I777+777?777?7777\033[0m" <<"           ::+::++::::::::::::::::::::::::  :\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "\033[1;31m        77:::777:::7777777I7+?77777\033[0m" <<"           :::::::::::::::::::::::::::::::::::\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "\033[1;31m          ?77+77::77:7777:::77:77+\033[0m" <<"            :::::::::::::::::::::::::::::::::::\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "\033[1;31m                7777:::777:::777+\033[0m" <<"             ::  ::::::::::::::::::::::::      :\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "\033[1;31m                7I 7:::+ 777    7+\033[0m" <<"                ::::::::::::::     :::        :\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "\033[1;31m                    7I          I7\033[0m" <<"               ::::::::::::::\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "                                                   :::::::::\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "                                                   :::::::\n";
    cout << "\n" << endl;
  }
  else // if they want to be Soviet Union
  {
    cout << "\n" << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "       7:::7" <<"\033[1;31m                                                                :::::\033[0m\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "       7:::777:::77:::77             " <<"\033[1;31m                                      :::::\033[0m\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "      7:::?7+777:::777::7I7?7      7777" <<"\033[1;31m              :::    ::           ::::::: :\033[0m\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "     ?7777:::77:77:::77:::7I77    77?77" <<"\033[1;31m        ::::+:::::  :     :::  :::::::::: ::\033[0m\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "     77:::7?7777:::77:77:::7 77 7777" <<"\033[1;31m        ::::::::::::::: :::::::::::::::::::  ::\033[0m\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "     I777:::777:77:::777::777:::77+?" <<"\033[1;31m         :::::::::::::::: :::::::::::::::::\033[0m\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "     777:::77::777:::7+77:77+??7::7" <<"\033[1;31m          ::::++:+::::::::::::::::::::::::\033[0m\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "      777:::77::77+I777+777?777?7777" <<"\033[1;31m           ::+::++::::::::::::::::::::::::  :\033[0m\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "        77:::777:::7777777I7+?77777" <<"\033[1;31m           :::::::::::::::::::::::::::::::::::\033[0m\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "          ?77+77::77:7777:::77:77" <<"\033[1;31m            :::::::::::::::::::::::::::::::::::\033[0m\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "                7777:::777:::777" <<"\033[1;31m             ::  ::::::::::::::::::::::::      :\033[0m\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "                7I 7:::+ 777    7" <<"\033[1;31m                ::::::::::::::     :::        :\033[0m\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "                  7I          I7" <<"\033[1;31m               ::::::::::::::\033[0m\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "\033[1;31m                                                   :::::::::\033[0m\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "\033[1;31m                                                   :::::::\033[0m\n";
    cout << "\n" << endl;

  }

}// End chooseCountry

void Map::displayDamageUS(int damage)
{

  if(damage <= 1000 && damage > 800)//damage values can be easily changed.  For now I am just testing
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "-----------------------------------------------------------"<< endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "USA:" << "\033[1;33m #####################################################\033[0m" << "|\n"; // yellow
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "-----------------------------------------------------------"<< endl;
  }
  if(damage <= 800 && damage > 600)
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "-----------------------------------------------------------"<< endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "USA:" << "\033[1;32m #########################################\033[0m" << "            |\n"; // green
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "-----------------------------------------------------------"<< endl;
  }

  if(damage <= 600 && damage > 400)
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "-----------------------------------------------------------"<< endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "USA:" << "\033[1;34m ##############################\033[0m" << "                       |\n"; // blue
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "-----------------------------------------------------------"<< endl;
  }
  if(damage <= 400 && damage > 200)
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "-----------------------------------------------------------"<< endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "USA:" << "\033[1;35m #################\033[0m" << "                                    |\n"; // magenta
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "-----------------------------------------------------------"<< endl;
  }
  if(damage <= 200 && damage >= 0)
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "-----------------------------------------------------------"<< endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "USA:" << "\033[1;31m ######\033[0m" << "                                               |\n"; // red
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "-----------------------------------------------------------"<< endl;
  }

}

void Map::displayDamageUSSR(int damage)
{

  if(damage <= 1000 && damage > 800)//damage values can be easily changed.  For now I am just testing
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "-----------------------------------------------------------"<< endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "USSR:" << "\033[1;33m ###################################################\033[0m" << "|\n"; // yellow
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "-----------------------------------------------------------"<< endl;
  }
  if(damage <= 800 && damage > 600)
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "-----------------------------------------------------------"<< endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "USSR:" << "\033[1;32m #########################################\033[0m" << "           |\n"; // green
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "-----------------------------------------------------------"<< endl;
  }

  if(damage <= 600 && damage > 400)
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "-----------------------------------------------------------"<< endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "USSR:" << "\033[1;34m ##############################\033[0m" << "                      |\n"; // blue
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "-----------------------------------------------------------"<< endl;
  }
  if(damage <= 400 && damage > 200)
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "-----------------------------------------------------------"<< endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "USSR:" << "\033[1;35m #################\033[0m" << "                                   |\n"; // magenta
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "-----------------------------------------------------------"<< endl;
  }
  if(damage <= 200 && damage >= 0)
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "-----------------------------------------------------------"<< endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "USSR:" << "\033[1;31m ######\033[0m" << "                                              |\n"; // red
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    cout << "-----------------------------------------------------------"<< endl;
  }

}
