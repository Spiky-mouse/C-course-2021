// Iuliia Orellana
// ID 223. Fall 21
// Final Project

#include <iostream> 
#include <string> 
#include <vector> 
#include <cctype> 
#include <cstdlib>
#include <ctime>

using namespace std; 

enum en_DIRS {NORTH, EAST, SOUTH, WEST}; 
enum en_ROOMS {CANYON, VILLAGE, MEADOW, FOREST, JUNGLE, MOUNTAINS, CAVE, LAKESHORE, MOUNTAINPEAK, GORGE, LAKE, WATERFALL, TAVERN, DWARFTOWN, WATERCAVE, DESERT, OASIS, RIVER, RIVERSIDE, SEA, BAG}; 
enum en_VERBS {GET, DROP, USE, OPEN, CLOSE, EXAMINE, INVENTORY, LOOK, COMBINE, DESTROY}; 
enum en_NOUNS {CAVE_DOOR, DRAGON_EGG, HERBS, COMPASS, GOLD, SNAKE_SKIN, PORTAL, FAIRY_DUST, STONE_WRITING, BERRIES, MUSHROOMS, TREE_CARVING, BOAT, ICE_SCULPTURE}; 

const int NONE = -1;
const int DIRS = 4;
const int ROOMS = 21;
const int VERBS = 10;
const int NOUNS = 14;

class words 
{
    private:
        string word;
        int code; 

    public:
        
        words(){}
        words(string wrd, int cd)
        {
            word = wrd;
            code = cd;
        }
        ~words(){}
        void setCode(int scode) {code = scode;}
        void setWord(string sword) {word = sword;}
        int getCode() {return code;}
        string getWord() {return word;}

};

class room 
{
    private:
        string description; 
        int exits_to_room[DIRS];
    public:
        room(){}
        room(string descrpt, int exitNorth, int exitEast, int exitSouth, int exitWest)
        {
            description = descrpt;
            exits_to_room[NORTH] = exitNorth;
            exits_to_room[EAST] = exitEast;
            exits_to_room[SOUTH] = exitSouth;
            exits_to_room[WEST] = exitWest;
            // cout << "Adding a " << description << ". It has exits to " << exits_to_room[NORTH];
            // cout << ", " << exits_to_room[EAST] << ", " << exits_to_room[SOUTH] << ", " << exits_to_room[WEST] << "." << endl;
        }
        ~room(){}  
        void setExits_to_room(int i, int exit) {exits_to_room[i] = exit;}
        void setDescription(string sdescription) {description = sdescription;}
        int getExits_to_room(int i) {return exits_to_room[i];}
        string getDescription() {return description;}
};

class noun
{
    private:
        string word; 
        string description; 
        int code; 
        int location; 
        bool can_carry; 
    public:
        
        noun(){}
        noun(string wrd, string descrp, int cd, int loc, bool carry)
        {
            word = wrd;
            description = descrp;
            code = cd;
            location = loc;
            can_carry = carry;
           // cout << "Creating " << description << " in location " << location << endl;
        }

        ~noun(){}
        void setWord(string sword) {word = sword;}
        void setDescription(string sdescription) {description = sdescription;}
        void setCode(int scode) {code = scode;}
        void setLocation(int slocation) {location = slocation;}
        void setCan_carry(bool scarry) {scarry = can_carry;}
        int getCode() {return code;}
        int getLocation() {return location;}
        string getDescription() {return description;}
        string getWord() {return word;}
        bool getCan_carry() {return can_carry;}
};

void set_rooms(vector<room>& rms) 
{
    room canyon("canyon", NONE, NONE, MEADOW, NONE);
    rms[CANYON] = canyon; 
    //rms[SPORTSHOP].setDescription("sports shop"); 
    //rms[SPORTSHOP].setExits_to_room(NORTH, NONE); 
    //rms[SPORTSHOP].setExits_to_room(EAST, NONE); 
    //rms[SPORTSHOP].setExits_to_room(SOUTH, CARPARK); 
    //rms[SPORTSHOP].setExits_to_room(WEST, NONE); 
    
    room village("elf village", NONE, TAVERN, FOREST, NONE);
    rms[VILLAGE] = village;
    //rms[CASINO].setDescription("bustling casino"); 
    //rms[CASINO].setExits_to_room(NORTH, NONE);
    //rms[CASINO].setExits_to_room(EAST, NONE); 
    //rms[CASINO].setExits_to_room(SOUTH, LOBBY); 
    //rms[CASINO].setExits_to_room(WEST, NONE); 
    
    room meadow("meadow", CANYON, FOREST, NONE, NONE);
    rms[MEADOW] = meadow;

    room forest("forest", VILLAGE, JUNGLE, MOUNTAINS, MEADOW);
    rms[FOREST] = forest;
    
    room jungle("jungle", NONE, NONE, NONE, FOREST);
    rms[JUNGLE] = jungle;

    room mountains("mountains", FOREST, NONE, MOUNTAINPEAK, NONE);
    rms[MOUNTAINS] = mountains;
    
    room cave("cave", NONE, NONE, NONE, NONE);
    rms[CAVE] = cave;
    
    room shore("lake shore", NONE, MOUNTAINPEAK, LAKE, NONE);
    rms[LAKESHORE] = shore;
    
    room peak("mountain's peak", MOUNTAINS, GORGE, DWARFTOWN, LAKESHORE);
    rms[MOUNTAINPEAK] = peak;

    room gorge("gorge", NONE, RIVER, DESERT, MOUNTAINPEAK);
    rms[GORGE] = gorge;
    
    room lake("lake", LAKESHORE, NONE, WATERFALL, NONE);
    rms[LAKE] = lake; 

    room waterfall("waterfall", LAKE, WATERCAVE, NONE, NONE);
    rms[WATERFALL] = waterfall;

    room tavern("tavern", NONE, NONE, VILLAGE, NONE);
    rms[TAVERN] = tavern;

    room town("dwarf town", MOUNTAINPEAK, NONE, WATERCAVE, WATERFALL);
    rms[DWARFTOWN] = town;

    room watercave("water cave", DWARFTOWN, NONE, NONE, WATERFALL);
    rms[WATERCAVE] = watercave;

    room desert("deadly desert", GORGE, RIVERSIDE, OASIS, NONE);
    rms[DESERT] = desert;

    room oasis("oasis", DESERT, NONE, NONE, NONE);
    rms[OASIS] = oasis;

    room river("river", NONE, SEA, RIVERSIDE, GORGE);
    rms[RIVER] = river;

    room sea("black sea", NONE, NONE, NONE, RIVER);
    rms[SEA] = sea;

    room bag("inventory", NONE, NONE, NONE, NONE);
    rms[BAG] = bag;
}


void set_directions(vector<words>& dir)
{
    words north("NORTH", NORTH);
    dir[NORTH] = north;
    // dir[NORTH].setCode(NORTH); 
    // dir[NORTH].setWord("NORTH"); 

    words east("EAST", EAST);
    dir[EAST] = east;

    words south("SOUTH", SOUTH);
    dir[SOUTH] = south;

    words west("WEST", WEST);
    dir[WEST] = west;
}

void set_verbs(vector<words>& vbs)
{
    //enum en_VERBS {GET, DROP, USE, OPEN, CLOSE, EXAMINE, INVENTORY, LOOK, COMBINE, DESTROY}; 

    words get("GET", GET);
    vbs[GET] = get;
    // vbs[GET].setCode(GET); 
    // vbs[GET].setWord("GET"); 
    
    words drop("DROP", DROP);
    vbs[DROP] = drop;
    // vbs[DROP].setCode(DROP); 
    // vbs[DROP].setWord("DROP"); 
    
    words use("USE", USE);
    vbs[USE] = use;
    
    words open("OPEN", OPEN);
    vbs[OPEN] = open;

    words close("CLOSE", CLOSE);
    vbs[CLOSE] = close;
    
    words examine("EXAMINE", EXAMINE);
    vbs[EXAMINE] = examine;  

    words inventory("INVENTORY", INVENTORY);
    vbs[INVENTORY] = inventory; 

    words look("LOOK", LOOK);
    vbs[LOOK] = look;

    words combine("COMBINE", COMBINE);
    vbs[COMBINE] = combine;

    words destroy("DESTROY", DESTROY);
    vbs[DESTROY] = destroy; 
}

void set_nouns(vector<noun>& nns)
{
    //enum en_NOUNS {CAVE_DOOR, DRAGON_EGG, HERBS, COMPASS, GOLD, SNAKE_SKIN}; 

    noun caveDoor("DOOR", "a closed cave door", CAVE_DOOR, MOUNTAINS, false);
    nns[CAVE_DOOR] = caveDoor;
    // nns[CAVE_DOOR].setWord("DOOR"); 
    // nns[CAVE_DOOR].setCode(CAVE_DOOR); 
    // nns[CAVE_DOOR].setDescription("a closed cave door"); 
    // nns[CAVE_DOOR].setCan_carry(false);
    // nns[CAVE_DOOR].setLocation(MOUNTAINS); 

    noun egg("EGG", "a dragon's egg", DRAGON_EGG, rand()%20, true);
    nns[DRAGON_EGG] = egg;
    // nns[DRAGON_EGG].setWord("EGG"); 
    // nns[DRAGON_EGG].setCode(DRAGON_EGG); 
    // nns[DRAGON_EGG].setDescription("a dragon's egg"); 
    // nns[DRAGON_EGG].setCan_carry(true);
    // nns[DRAGON_EGG].setLocation(MOUNTAINPEAK);

    noun herbs("HERBS", "healing herbs", HERBS, rand()%20, true);
    nns[HERBS] = herbs;

    noun compass("COMPASS", "a compass", COMPASS, rand()%20, true);
    nns[COMPASS] = compass;

    noun gold("GOLD", "gold coins", GOLD, rand()%20, true);
    nns[GOLD] = gold;

    noun skin("SKIN", "a snake skin", SNAKE_SKIN, rand()%20, true);
    nns[SNAKE_SKIN] = skin;

    noun portal("PORTAL", " a portal to unknown location", PORTAL, WATERFALL, false);
    nns[PORTAL] = portal;

    noun dust("DUST", "fairy dust", FAIRY_DUST, rand()%20, true);
    nns[FAIRY_DUST] = dust;

    noun writing("WRITING", "a writing on a stone", STONE_WRITING, MOUNTAINS, false);
    nns[STONE_WRITING] = writing;

    noun berries("BERRIES", "berries on a bush", BERRIES, rand()%20, true);
    nns[BERRIES] = berries;

    noun mushrooms("MUSHROOMS", "mushrooms", MUSHROOMS, rand()%20, true);
    nns[MUSHROOMS] = mushrooms;

    noun carving("CARVING", "a carving on a tree", TREE_CARVING, FOREST, false);
    nns[TREE_CARVING] = carving;

    noun boat("BOAT", "a boat", BOAT, SEA, false);
    nns[BOAT] = boat;

    noun sculpture("SCULPTURE", "a sculpture made of ice", ICE_SCULPTURE, MOUNTAINPEAK, false);
    nns[ICE_SCULPTURE] = sculpture;
}

void section_command(string Cmd, string &wdl, string &wd2)
{
    string sub_str; 
    vector<string> words; 
    char search = ' '; 
    short int i , j ; 
    
    for(i = 0; i < Cmd.size(); i++) 
    {
        if(Cmd.at(i) != search) 
        { 
            sub_str.insert(sub_str.end(), Cmd.at(i)); 
        } 
        if(i == Cmd.size() - 1) 
        { 
            words.push_back(sub_str); 
            sub_str.clear(); 
        }
        if(Cmd.at(i) == search)
        {
            words.push_back(sub_str); 
            sub_str.clear();     
        }
    }
    for(i = words.size() - 1; i > 0; i--)
    {
        if(words.at(i) == "")
        {
            words.erase(words.begin() + i);
        }
    }
    for(i = 0; i < words.size(); i++)
    {
        for(j = 0; j < words.at(i).size(); j++)
        {
            if(islower(words.at(i).at(j)))
            {
                words.at(i).at(j) = toupper(words.at(i).at(j));
            }
        }
    }
    
    if(words.size() == 0) 
    {
        cout << "No command given" << endl;
    }
    if(words.size() == 1) 
    {
        wdl = words.at(0);
    }
    if(words.size() == 2)
    {
        wdl = words.at(0); 
        wd2 = words.at(1);
    }
    if(words.size() > 2)
    {
        cout << "Command too long. Only type one or two words (direction or verb and noun)"<< endl; 
    }
}

void look_around(int loc, vector<room>& rms, vector<words>& dir, vector<noun>& nns)
{
    int i;
    cout << "I am in a " << rms[loc].getDescription() << "." << endl;

    for(i = 0; i < DIRS; i++)
    {
        if(rms[loc].getExits_to_room(i) != NONE) 
        { 
            cout << "There is a path " << dir[i].getWord() << " to " << rms[rms[loc].getExits_to_room(i)].getDescription() << "." << endl;
        }
    }

    //The look command should check which objects (nouns) are in the current room and report them to the player. 
    for(i = 0; i < NOUNS; i++) 
    {
        if(nns[i].getLocation() == loc)
        {
            cout << "I see " << nns[i].getDescription() << "." << endl;
        }
    }
}



bool parser(int &loc, string wd1, string wd2, vector<words>& dir, vector<words>& vbs, vector<room>& rms, vector<noun>& nns)
{
    static bool doorIsOpen = false; //false is closed door. 
    
    int i; 
    for(i = 0; i < DIRS; i++) 
    {
        if(wd1 == dir[i].getWord())
        {
            if(rms[loc].getExits_to_room(dir[i].getCode()) != NONE)
            {
                loc = rms[loc].getExits_to_room(dir[i].getCode()); 
                cout << "I am now in a " << rms[loc].getDescription() << "." << endl;
                 // A special case for the cave door. 
                 if(loc == CAVE || loc == MOUNTAINS) 
                 {
                     nns[CAVE_DOOR].setLocation(loc);
                 }
                 return true;
            }
            else
            {
                cout << "No exit that way." << endl; 
                return true;     
            }
        }
    }


    int VERB_ACTION = NONE;
    int NOUN_MATCH = NONE;

    for(i = 0; i < VERBS; i++)
    {
        if(wd1 == vbs[i].getWord())
        {
            VERB_ACTION = vbs[i].getCode(); 
            break;     
        }
    }


    if(wd2 != "")
    {
        for(i = 0; i < NOUNS; i++)
        {
            if(wd2 == nns[i].getWord())
            {
                NOUN_MATCH = nns[i].getCode();
                break;
            }
        }
    }
    if(VERB_ACTION == NONE)
    {
        cout << "No valid command entered." << endl; 
        return true; 
    }
    if(VERB_ACTION == LOOK)
    {
        look_around(loc, rms, dir, nns); 
        return true; 
    }

    //Actions for usage of VERB GET
    if (VERB_ACTION == GET)
    {
         for (i = 0; i < NOUNS; i++)
        {
            if (NOUN_MATCH == nns[i].getCode() & loc == nns[i].getLocation())
            {
                if (nns[i].getCan_carry())
                {
                    cout << "Picking up " << nns[i].getDescription() << "." << endl;
                    nns[i].setLocation(BAG);
                }
                
                else
                {
                    cout << "Can't get that." << endl;
                }
            }

        }
    }

    //Actions for usage of VERB INVENTORY
    if (VERB_ACTION == INVENTORY)
    {
        cout << "You have: \n";
        for(i = 0; i < NOUNS; i++) 
        {
            if(nns[i].getLocation() == BAG)
            {
                cout << nns[i].getDescription() << endl;
            }
        }
    }

    //Actions for usage of VERB USE 
    if (VERB_ACTION == USE)
    {
        if (NOUN_MATCH == PORTAL)
        {
            cout << "Going through the portal." << endl;
            loc = rand()%20;
            cout << "I am at " << rms[loc].getDescription() << "." << endl; 
        }
    }


    //Actions for usage of VERB OPEN 
    if(VERB_ACTION == OPEN)
    {
        if(NOUN_MATCH == CAVE_DOOR)
        {
            if(loc == MOUNTAINS || loc == CAVE) 
            {
                if(doorIsOpen == false)
                {
                    doorIsOpen = true; 
                    rms[MOUNTAINS].setExits_to_room(EAST, CAVE); 
                    rms[CAVE].setExits_to_room(WEST, MOUNTAINS); 
                    nns[CAVE_DOOR].setDescription(""); 
                    nns[CAVE_DOOR].setDescription("an open cave door"); 
                    cout << "I have opened the door." << endl; 
                    return true; 
                }
                else if(doorIsOpen == true)
                {
                    cout << "The door is already open." << endl; 
                    return true; 
                }
            }
            else
            {
                cout << "There is no door to open here." << endl; 
                return true; 
            }
        }
        else
        {
            cout << "Opening that is not possible." << endl; 
            return true; 
        }
    } 
    return false;
}

int main()
{
    string command; 
    string word_1; 
    string word_2;
    srand(time(0)); 

    vector<room> rooms(ROOMS); 
    set_rooms(rooms); 
    //room bar("bar", NONE, POOL, NONE, GARDEN);

    vector<words> directions(DIRS); 
    set_directions(directions);

    vector<words> verbs(VERBS); 
    set_verbs(verbs); 

    vector<noun> nouns(NOUNS); 
    set_nouns(nouns); 

    int location = MEADOW; 
    
    while(word_1 != "QUIT") 
    {
        command.clear(); 
        cout << "What shall I do? "; 
        getline(cin, command); 

        word_1.clear(); 
        word_2.clear();

        section_command(command, word_1, word_2);

        if(word_1 != "QUIT") 
        {
            parser(location, word_1, word_2, directions, verbs, rooms, nouns);
        }
    }

    return 0;
}


