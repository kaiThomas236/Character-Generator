#ifndef CHARACTERGENERATOR
#define CHARACTERGENERATOR

#include <string>
#include <iostream>
#include <vector>

using namespace std;



struct Class
{
  //vector<Class> Classes;
  string className;
  int level; // only going to do levels 1-5 for first implementation (very little need to have starting character above five levels)
  int profBonus;
  string HP;
  string hitDie;
  string miscProf;
  string weaponProf;
  string armorProf;
  string saveProf;
  string skillProf;
  string classFeats;
  string featPerRest;
  string classEquip;
};

struct Race
{
  //vector<Race> Races;
  string raceName;
  int strMod;
  int intMod;
  int dexMod;
  int chaMod;
  int wisMod;
  int conMod;
  string size;
  int speed;
  string perk1, perk2, perk3;
  string language1, language2;

};

struct Background
{
  //vector<Background> Backgrounds;
  string backgroundName;
  string skillProf;
  string toolProf;
  string equipment;
  string feat;
};


class player // tbh my boy it'd be chill as hell to hardcod some random things you might need,
{             //this doesnt have to be autograded and functionality is more important
public:
  player();
  void userMenu(); //will ask user all the q's
  void printArray();
  //void setUnimportantTraits(); // includes height and age, name, alignment dumb shit like that
  void setPlayerClass(string className, int level); // each of thes sets all the member variables of a node of that type
  void setPlayerRace(string raceName);
  void setPlayerBackground(string backgroundName);
  int randNum(int max); //rand num generator to simulate dice rolls, should be (1, max) inclusive
  void insertClassData(int i, string className, int level, int profBonus, string hp, string hitDie, string weaponProf, string armorProf, string saveProf, string skillProf, string classFeats, string featPerRest, string classEquip);
  void insertRaceData(int i, string raceName, int strMod, int intMod, int dexMod, int chaMod, int wisMod, int conMod, string size, int speed, string perk1, string perk2, string perk3, string language1, string language2);
  void insertBackgroundData(int i, string backgroundName, string skillProf, string toolProf, string equipment, string feat);
  void printPlayer();
  string playerName, characterName;
  string raceName, className, backgroundName;
  int level;
  int profBonus;
  string hp;
  int hP;
  string hitDie;
  string miscProf;
  string featPerRest;
  string classFeats;
  string saveProfs;
  string skillProfs;
  int strScore;
  int intScore;
  int dexScore;
  int chaScore;
  int wisScore;
  int conScore;
  string size;
  int speed;
  string perks[6];
  string languages[4];
  string toolProf;
  string weaponProf;
  string armorProf;
  vector <string> equipment;
  string feat, height, weight;
  int age;
  string personalityTraits[4];
  string alignment;
  Class **Classes;
  Race **Races;
  Background **Backgrounds;
};


#endif
