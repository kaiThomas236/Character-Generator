#include "CharacterGenerator.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//cd C:\Users\Kai Thomas\Documents\CSCI 2270\final

//g++ -std=c++11 characterGenerator.cpp -o char && char

//player p;

player::player()
{
  Classes = new Class*[20];
  Races = new Race*[4];
  Backgrounds = new Background*[4];
  for (int i = 0; i < 20; i++)
  {
    Classes[i] = NULL;
  }
  for (int i = 0; i < 4; i++)
  {
    Races[i] = NULL;
    Backgrounds[i] = NULL;
  }
}



int hashFunc(string type, int level, string name)
{
  int key = 0;
  if (level != -1)
  {
    for (int i = 0; i < name.length(); i++)
    {
       key += (int)name[i];
    }
    int temp = key + level;
    int index = temp % 20;
    return index;
  }
  else
  {
    if (type == "Race")
    {
      for (int i = 0; i < name.length(); i++)
      {
         key += (int)name[i];
      }
      int temp = key + level;
      int index = temp % 4;
      return index;
    }
    else if (type == "Background")
    {
      for (int i = 0; i < name.length(); i++)
      {
         key += (int)name[i];
      }
      int temp = key + level;
      int index = temp % 4;
      return index;
    }
  }
}



void player::insertClassData(int i, string className, int level, int profBonus, string hp, string hitDie, string weaponProf, string armorProf, string saveProf, string skillProf, string classFeats, string featPerRest, string classEquip)
{
//  cout<< i << endl;
  while (Classes[i] != NULL && i < 20) // add this to race and background using table size 4
  {
    i++;
    if (i == 20)
      i = 0;
  }
  //cout << i << endl;

    Classes[i] = new Class;
    Classes[i]->className = className;
    //cout << Classes[i]->className << endl;
    Classes[i]->level = level;
    Classes[i]->profBonus = profBonus;
    Classes[i]->HP = hp;
    Classes[i]->hitDie = hitDie;
    Classes[i]->weaponProf = weaponProf;
    Classes[i]->armorProf = armorProf;
    Classes[i]->saveProf = saveProf;
    Classes[i]->skillProf = skillProf;
    Classes[i]->classFeats = classFeats;
    Classes[i]->featPerRest = featPerRest;
    Classes[i]->classEquip = classEquip;





  //cout << Classes[i]->className << " | " << Classes[i]->level << " | " << Classes[i]->profBonus << " | " << Classes[i]->HP << " | " << Classes[i]->hitDie << " | " << Classes[i]->weaponProf << " | " << Classes[i]->armorProf << " | " << Classes[i]->saveProf << " | " << Classes[i]->skillProf << " | " << Classes[i]->classFeats << " | " << Classes[i]->featPerRest << " | " << Classes[i]->classEquip << endl;
}

void player::insertRaceData(int i, string raceName, int strMod, int intMod, int dexMod, int chaMod, int wisMod, int conMod, string size, int speed, string perk1, string perk2, string perk3, string language1, string language2)
{
  //player p;
  while (Races[i] != NULL && i < 4) // add this to race and background using table size 4
  {
    i++;
    if (i == 4)
      i = 0;
  }
  //cout << "race"<< i << endl;
  Races[i] = new Race;
  Races[i]->raceName = raceName;
  Races[i]->strMod = strMod;
  Races[i]->intMod = intMod;
  Races[i]->dexMod = dexMod;
  Races[i]->chaMod = chaMod;
  Races[i]->wisMod = wisMod;
  Races[i]->conMod = conMod;
  Races[i]->size = size;
  Races[i]->speed = speed;
  Races[i]->perk1 = perk1;
  Races[i]->perk2 = perk2;
  Races[i]->perk3 = perk3;
  Races[i]->language1 = language1;
  Races[i]->language2 = language2;

  //cout << Races[i]->raceName << " | " << Races[i]->strMod << " | "<< Races[i]->intMod << " | "<< Races[i]->dexMod << " | "<< Races[i]->chaMod << " | "<< Races[i]->wisMod << " | "<< Races[i]->conMod << " | "<< Races[i]->size << " | "<< Races[i]->perk1 << " | "<< Races[i]->perk2 << " | "<< Races[i]->perk3 << " | "<< Races[i]->language1 << " | " << Races[i]->language1 << endl;
}



void player::insertBackgroundData(int i, string backgroundName, string skillProf, string toolProf, string equipment, string feat) // most background info is just to be printed out, only skillprof usually
{
  //player p;
  while (Backgrounds[i] != NULL && i < 4) // add this to race and background using table size 4
  {
    i++;
    if (i == 4)
      i = 0;
  }
  //cout << "back" << i << endl;
  Backgrounds[i] = new Background;
  Backgrounds[i]->backgroundName = backgroundName;
  Backgrounds[i]->skillProf = skillProf;
  Backgrounds[i]->toolProf = toolProf;
  Backgrounds[i]->equipment = equipment;
  Backgrounds[i]->feat = feat;

  //cout << Backgrounds[i]->backgroundName << " | " << Backgrounds[i]->skillProf << " | " << Backgrounds[i]->toolProf << " | " << Backgrounds[i]->equipment << " | " << Backgrounds[i]->feat << endl;
}

/*
void player::printArray()
{
  for (int i = 0; i < 20; i++)
  {
    cout << Classes[i]->className << endl;
  }
}*/


void player::userMenu()
{
  string start;
  string align;
  cout << "What is your human name? ";
  cin >> playerName;
  cout << "Would you like to build a character? This program is in the early stages of development so you will have limited options, but if you would like to go ahead, input Y, if not, input N: ";
  cin >> start;
  if(start == "Y")
  {
    string name;
    cout << "What would you like your characters name to be? ";
    cin.ignore();
    getline(cin, name);
    characterName = name;
    cout << characterName;
    string playerClass;
    int playerLevel;
    string scoreLine;
    string first, second, third, fourth, fifth, sixth;
    cout << endl << "Please rank your ability scores (Strength, Intelligence, Dexterity, Wisdom, Charisma, and Constitution) from highest desired score to lowest by inputting them in descending order: ";
    cin >> scoreLine;

    stringstream ss(scoreLine);
    getline(ss, first, ',');
    getline(ss, second, ',');
    getline(ss, third, ',');
    getline(ss, fourth, ',');
    getline(ss, fifth, ',');
    getline(ss, sixth, ',');
    if (first == "Strength")
      strScore = 15;
    else if (first == "Intelligence")
      intScore = 15;
    else if (first == "Dexterity")
      dexScore = 15;
    else if (first == "Wisdom")
      wisScore = 15;
    else if (first == "Charisma")
      chaScore = 15;
    else if (first == "Constitution")
      conScore = 15;
    if (second == "Strength")
      strScore = 14;
    else if (second == "Intelligence")
      intScore = 14;
    else if (second == "Dexterity")
      dexScore = 14;
    else if (second == "Wisdom")
      wisScore = 14;
    else if (second == "Charisma")
      chaScore = 14;
    else if (second == "Constitution")
      conScore = 14;
    if (third == "Strength")
      strScore = 13;
    else if (third == "Intelligence")
      intScore = 13;
    else if (third == "Dexterity")
      dexScore = 13;
    else if (third == "Wisdom")
      wisScore = 13;
    else if (third == "Charisma")
      chaScore = 13;
    else if (third == "Constitution")
      conScore = 13;
    if (fourth == "Strength")
      strScore = 12;
    else if (fourth == "Intelligence")
      intScore = 12;
    else if (fourth == "Dexterity")
      dexScore = 12;
    else if (fourth == "Wisdom")
      wisScore = 12;
    else if (fourth == "Charisma")
      chaScore = 12;
    else if (fourth == "Constitution")
      conScore = 12;
    if (fifth == "Strength")
      strScore = 10;
    else if (fifth == "Intelligence")
      intScore = 10;
    else if (fifth == "Dexterity")
      dexScore = 10;
    else if (fifth == "Wisdom")
      wisScore = 10;
    else if (fifth == "Charisma")
      chaScore = 10;
    else if (fifth == "Constitution")
      conScore = 10;
    if (sixth == "Strength")
      strScore = 8;
    else if (sixth == "Intelligence")
      intScore = 8;
    else if (sixth == "Dexterity")
      dexScore = 8;
    else if (sixth == "Wisdom")
      wisScore = 8;
    else if (sixth == "Charisma")
      chaScore = 8;
    else if (sixth == "Constitution")
      conScore = 8;
    cout << "Great! For your class would you like to be a Rogue, Barbarian, Fighter, or a Ranger? ";
    cin >> playerClass;
    cout << "Please pick a starting level for your character from 1 - 5: ";
    cin >> playerLevel;
    setPlayerClass(playerClass, playerLevel);
    string data = "";
    int num, times, max = 0;
    for (int i = 0; i < hp.length(); i++)
    {
      if (hp[i] == 'd')
      {
        data = hp.substr(0, i);
        times = stoi(data);
      }
      else if (level == 1)
      {
        num = stoi(hp);
      }
      data = hp.substr(i+1, hp.length());
      cout << data << endl;
      max = stoi(data);
    }
    string playerRace, playerBack;
    cout << "For your race would you like to be a Human, Elf, Dwarf, or Dragonborn? ";
    cin >> playerRace;
    setPlayerRace(playerRace);
    cout << "For your background would you like to be a Criminal, Folk Hero, Outlander, or Sailor? ";
    cin >> playerBack;
    setPlayerBackground(playerBack);

    cout << times << " " << max;
    cout << "Please choose an alignment (Lawful Good, Lawful Neutral , Lawful Evil, Neutral Good, True Neutral , Neutral Evil, Chaotic Good, Chaotic Neutral , or Chaotic Evil) for your character, input the two letter acronym for your alignment using only capitals: ";
    cin >> align;
    alignment = align;
    cout << "How old is your character? ";
    cin >> age;
    cout << "How tall is your character? Dont forget units: ";
    cin.ignore();
    getline(cin, height);
    cout << "How much does your character weigh? Dont forget units: ";
    cin.ignore();
    getline(cin, weight);
  }
  else
    cout << "Goodbye!" << endl;

}

void player::setPlayerClass(string playerClass, int playerLevel)
{

  //cout << playerClass << " | " << playerLevel << endl;
  for (int i = 0; i < 20; i++)
  {
    if (playerClass == Classes[i]->className && playerLevel == Classes[i]->level)
    {
      //cout << "inf the if" << endl;
      className = Classes[i]->className;
      level = Classes[i]->level;
      profBonus = Classes[i]->profBonus;
      hp = Classes[i]->HP;
      hitDie = Classes[i]->hitDie;
      weaponProf = Classes[i]->weaponProf;
      armorProf = Classes[i]->armorProf;
      saveProfs = Classes[i]->saveProf;
      skillProfs = Classes[i]->skillProf;
      classFeats = Classes[i]->classFeats;
      featPerRest = Classes[i]->featPerRest;
      equipment.push_back(Classes[i]->classEquip);

    }

  }


}

void player::setPlayerRace(string playerRace)
{
  for (int i = 0; i < 4; i++)
  {
    if (playerRace == Races[i]->raceName)
    {
      raceName = Races[i]->raceName;
      strScore += Races[i]->strMod;
      intScore += Races[i]->intMod;
      dexScore += Races[i]->dexMod;
      chaScore += Races[i]->chaMod;
      wisScore += Races[i]->wisMod;
      conScore += Races[i]->conMod;
      size = Races[i]->size;
      speed = Races[i]->speed;
      perks[0] = Races[i]->perk1;
      perks[1] = Races[i]->perk2;
      perks[2] = Races[i]->perk3;
      languages[0] = Races[i]->language1;
      languages[1] = Races[i]->language2;

    }
  }
}

void player::setPlayerBackground(string playerBack)
{
  for (int i = 0; i < 4; i++)
  {
    if (playerBack == Backgrounds[i]->backgroundName)
    {
      backgroundName = Backgrounds[i]->backgroundName;
      skillProfs.append(Backgrounds[i]->skillProf);
      toolProf = Backgrounds[i]->toolProf;
      equipment.push_back(Backgrounds[i]->equipment);
      feat = Backgrounds[i]->feat;

    }
  }
}

int player::randNum(int max)
{

}


void player::printPlayer()
{
  ofstream charFile("charOutput.txt");
  charFile <<  playerName << " " << characterName << " " << age << " " << classFeats << " " << toolProf << " " << hitDie << endl;

  //cout << playerName << " " << characterName << " " << age << " " << classFeats << " " << toolProf << " " << hitDie << endl;
}



int main()
{
  //Class *c;
  //Race *r;
  //Background *b;
  player p;
  ifstream finalFile("finalData.txt");
  string type, size, race, perk1, perk2, perk3, perk4, language1, language2 = "";
  string line = "";
  string name = "";
  string data = "";
  int level, i, speed = 0;
  if (finalFile.is_open())
  {
    while (getline(finalFile, line))
    {
      int profBonus = 0;
      string hp, hitDie, weaponProf, armorProf, saveProf, skillProf, classFeats, featPerRest, classEquip = "";
      //cout << line << endl;
      stringstream ss(line);
      getline(ss, type, ',');
      if (type == "Class")
      { //theres some weird shit going
        //string hitDie, weaponProf, armorProf, saveProf, skillProf, classFeats, featPerRest, classEquip = "";
        getline(ss, name, ','); //on in the last few columns of the classes int he file
        //cout << name << endl;
        getline(ss, data, ',');
        level = stoi(data);
        i = hashFunc(type, level, name);
        //c->Classes.emplace(i, name).className;
        //cout << c->Classes[i].className << endl;
        //c->Classes[i].level = level;
        getline(ss, data, ',');
        profBonus = stoi(data);
        getline(ss, hp, ','); //test all this soon
        getline(ss, hitDie, ',');
        getline(ss, weaponProf, ',');
        getline(ss, armorProf, ',');
        getline(ss, saveProf, ',');
        getline(ss, skillProf, ',');
        getline(ss, classFeats, ',');
        getline(ss, featPerRest, ',');
        getline(ss, classEquip, ',');
        p.insertClassData(i, name, level, profBonus, hp, hitDie, weaponProf, armorProf, saveProf, skillProf, classFeats, featPerRest, classEquip);
      }
      else if (type == "Race")
      {
        getline(ss, name, ',');
        i = hashFunc(type, -1, name);
        getline(ss, data, ',');
        //cout << data << endl;
        int strMod = stoi(data);
        getline(ss, data, ',');
        int intMod = stoi(data);
        getline(ss, data, ',');
        int dexMod = stoi(data);
        getline(ss, data, ',');
        int chaMod = stoi(data);
        getline(ss, data, ',');
        int wisMod = stoi(data);
        getline(ss, data, ',');
        int conMod = stoi(data);
        getline(ss, size, ',');
        getline(ss, data, ',');
        speed = stoi(data);
        getline(ss, perk1, ',');
        getline(ss, perk2, ',');
        getline(ss, perk3, ',');
        getline(ss, perk4, ',');
        getline(ss, language1, ',');
        getline(ss, language2, ',');
        p.insertRaceData(i, name, strMod, intMod, dexMod, chaMod, wisMod, conMod, size, speed, perk1, perk2, perk3, language1, language2);

      }
      else if (type == "Background")
      {
        string skillProf, toolProf, equipment, feat = "";
        getline(ss, name, ',');
        i = hashFunc(type, -1, name);
        getline(ss, skillProf, ',');
        getline(ss, toolProf, ',');
        getline(ss, equipment, ',');
        getline(ss, feat, ',');
        p.insertBackgroundData(i, name, skillProf, toolProf, equipment, feat);

      }


    }
    //p.printArray();
    cout << "class data inserted" << endl;
    cout << "race data inserted" << endl;
    cout << "background data inserted" << endl;
  }
  p.userMenu();
  p.printPlayer();


}
