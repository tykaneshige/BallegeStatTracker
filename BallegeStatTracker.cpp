#include <iostream>
#include <iomanip>
#include <string>

#define BOARD_SIZE 46

#define MAX_PLAYERS 5

// Player Class
class Player
{
    public:

        // Constructor
        Player(const std::string name) {
            m_name = name;
            m_assists = 0;
            m_rebounds = 0;
            m_steals = 0;
            m_turnovers = 0;
            m_pm = 0;
            m_pm3 = 0;
            m_fgm = 0;
            m_fga = 0;
        }

        /* --- Modifier Functions --- */

        void changeName(const std::string name) {
            m_name = name;
        }

        void editAssists(const int num) {
            m_assists += num;
        }

        void editRebounds(const int num) {
            m_rebounds += num;
        }

        void editSteals(const int num) {
            m_steals += num;
        }

        void editTurnovers(const int num) {
            m_turnovers += num;
        }

        void editPm(const int num) {
            m_pm += num;
        }

        void editPm3(const int num) {
            m_pm3 += num;
        }

        void editFgm(const int num) {
            m_fgm += num;
        }

        void editFga(const int num) {
            m_fga += num;
        }

        /* --- Accessor Functions --- */

        std::string getName() const {
            return m_name;
        }

        int getAssists() const {
            return m_assists;
        }

        int getRebounds() const {
            return m_rebounds;
        }

        int getSteals() const {
            return m_steals;
        }

        int getTurnovers() const {
            return m_turnovers;
        }

        int getPm() const {
            return m_pm;
        }

        int getPm3() const {
            return m_pm3;
        }

        int getFgm() const {
            return m_fgm;
        }

        int getFga() const {
            return m_fga;
        }

    private:

        // General Information
        std::string m_name;
        
        // Team Statistics
        int m_assists;
        int m_rebounds;
        int m_steals;
        int m_turnovers;

        // Point Statistics
        int m_pm;                         // Total Points
        int m_pm3;                        // Three-Pointers

        // Shot Statistics
        int m_fgm;                        // Field Goals Made
        int m_fga;                        // Field Goals Attempted   
};

// Statboard Class
class Statboard
{
    public:

        // Constructor
        Statboard(const int pointValue) {
            m_numTeam1 = 0;
            m_numTeam2 = 0;
            m_score1 = 0;
            m_score2 = 0;

            // If an invalid point value is passed, set to default point value
            if ((pointValue != 1) && (pointValue != 2)) {
                m_pointValue = 2;
            } else {
                m_pointValue = pointValue;
            }
        }

        // Destructor
        ~Statboard() {
            
            // Delete all dynamically allocated players on team 1
            for (int i = 0; i < m_numTeam1; i++) {
                delete m_team1[i];
            }

            // Delete all dynamically allocated players on team 2
            for (int j = 0; j < m_numTeam2; j++) {
                delete m_team2[j];
            }
        }

        /* --- Player Functions --- */

        // Adds a player to the board
        void addPlayer(const int team, const std::string name) {

            // Verify that a player can be added to the specified team
            if ((team == 1) && (m_numTeam1 < 5)) {
                m_team1[m_numTeam1] = new Player(name);
                m_numTeam1++;
            } else if ((team == 2) && (m_numTeam2 < 5)) {
                m_team2[m_numTeam2] = new Player(name);
                m_numTeam2++;
            } else {
                std::cout << "Unable to add player." << std::endl;
            }

        }

        // bool editPlayer(int player, std::string name);
        // void removePlayer(int player);
        // void switchPlayer(int p1, int p2);

        /* --- Stat Functions --- */
        
        // Edits assists for a specified player
        void editAssists(int team, int player, int numAssists) {
            if ((team == 1) && (player <= m_numTeam1)) {
                m_team1[player-1]->editAssists(numAssists);
            } else if ((team == 2) && (player <= m_numTeam2)) {
                m_team2[player-1]->editRebounds(numAssists);
            }
        }

        // Edits rebounds for a specified player
        void editRebounds(int team, int player, int numRebounds) {
            if ((team == 1) && (player <= m_numTeam1)) {
                m_team1[player-1]->editRebounds(numRebounds);
            } else if ((team == 2) && (player <= m_numTeam2)) {
                m_team2[player-1]->editRebounds(numRebounds);
            }
        }

        // Edits steals for a specified player
        void editSteals(int team, int player, int numSteals) {
            if ((team == 1) && (player <= m_numTeam1)) {
                m_team1[player-1]->editSteals(numSteals);
            } else if ((team == 2) && (player <= m_numTeam2)) {
                m_team2[player-1]->editSteals(numSteals);
            }
        }

        // Edits turnovers for a specified player
        void editTurnovers(int team, int player, int numTurnovers) {
            if ((team == 1) && (player <= m_numTeam1)) {
                m_team1[player-1]->editTurnovers(numTurnovers);
            } else if ((team == 2) && (player <= m_numTeam2)) {
                m_team2[player-1]->editTurnovers(numTurnovers);
            }
        }

        // Edits 1/2-pointers for a specified player
        void editPm(int team, int player, int numPm) {
            if ((team == 1) && (player <= m_numTeam1)) {
                m_team1[player-1]->editPm(numPm);
                m_score1 += m_pointValue * numPm;
            } else if ((team == 2) && (player <= m_numTeam2)) {
                m_team2[player-1]->editPm(numPm);
                m_score2 += m_pointValue * numPm;
            }
        }

        // Edits 2/3-pointers for a specified player
        void editPm3(int team, int player, int numPm3) {
            if ((team == 1) && (player <= m_numTeam1)) {
                m_team1[player-1]->editPm3(numPm3);
                m_score1 += (m_pointValue + 1) * numPm3;
            } else if ((team == 2) && (player <= m_numTeam2)) {
                m_team2[player-1]->editPm3(numPm3);
                m_score2 += (m_pointValue + 1) * numPm3;
            }
        }

        // Edits shots made for a specified player
        void editFgm(int team, int player, int numFgm) {
            if ((team == 1) && (player <= m_numTeam1)) {
                m_team1[player-1]->editFgm(numFgm);
            } else if ((team == 2) && (player <= m_numTeam2)) {
                m_team2[player-1]->editFgm(numFgm);
            }
        }
        
        // Edits shots attempted for a specified player
        void editFga(int team, int player, int numFga) {
            if ((team == 1) && (player <= m_numTeam1)) {
                m_team1[player-1]->editFga(numFga);
            } else if ((team == 2) && (player <= m_numTeam2)) {
                m_team2[player-1]->editFga(numFga);
            }
        }

        /* --- Board Functions --- */

        // Prints entire board
        void printBoard() const {

            // Print team 1 stats
            std::cout << std::endl;
            printLine();
            printHeader(1);
            for (int i = 0; i < m_numTeam1; i++) {
                printLine();
                printPlayer(m_team1[i], i+1);
            }

            printLine();
            std::cout << std::setfill(' ') << "Score: " << std::setw(2) << m_score1 << std::setw(37) << std::right << "|" << std::endl;
            printLine();
            std::cout << std::endl;

            // Print team 2 stats
            printLine();
            printHeader(2);
            for (int j = 0; j < m_numTeam2; j++) {
                printLine();
                printPlayer(m_team2[j], j+1);
            }

            printLine();
            std::cout << std::setfill(' ') << "Score: " << std::setw(2) << m_score2 << std::setw(37) << std::right << "|" << std::endl;
            printLine();
            std::cout << std::endl;
        }

        // Prints the stats of a single player
        void printPlayer(const Player *player, int num) const {
            std::cout << num << ". " << std::left << std::setw(10) << std::setfill(' ') << player->getName();
            std::cout << "|" << std::right << std::setw(3) << player->getAssists();
            std::cout << "|" << std::right << std::setw(3) << player->getRebounds();
            std::cout << "|" << std::right << std::setw(3) << player->getSteals();
            std::cout << "|" << std::right << std::setw(3) << player->getTurnovers();
            std::cout << "|" << std::right << std::setw(3) << player->getPm();
            std::cout << "|" << std::right << std::setw(3) << player->getPm3();
            std::cout << "|" << std::right << std::setw(3) << player->getFgm();
            std::cout << "|" << std::right << std::setw(3) << player->getFga() << "|" << std::endl;

        }

        // Prints out board header
        void printHeader(const int team) const {
            std::cout << std::setfill(' ') << "Team " << team << std::setw(7) << "";
            std::cout << "|" << std::right << std::setw(3) << "As";
            std::cout << "|" << std::right << std::setw(3) << "Rb";
            std::cout << "|" << std::right << std::setw(3) << "St";
            std::cout << "|" << std::right << std::setw(3) << "Tu";
            std::cout << "|" << std::right << std::setw(3) << "Pm";
            std::cout << "|" << std::right << std::setw(3) << "Pm3";
            std::cout << "|" << std::right << std::setw(3) << "Fgm";
            std::cout << "|" << std::right << std::setw(3) << "Fga" << "|" << std::endl;
        }

        // Prints a line of dashes
        void printLine() const {
            std::cout << std::setw(BOARD_SIZE) << std::setfill('-') << "" << std::endl;
        }

        /* --- File Functions --- */

        // void exportBoard();

        /* --- Modifier Functions --- */

        // Updates base point value of game
        void updatePointValue(int newPointValue) {

            // Only update if a valid point valid is passed
            if ((newPointValue == 1) || (newPointValue == 2)) {
                m_pointValue = newPointValue;
            }
        }

        /* --- Accessor Functions --- */

        int getPointValue() {
            return m_pointValue;
        }

    private:

        // Team 1 Variables
        Player *m_team1[MAX_PLAYERS];
        int m_numTeam1;
        int m_score1;

        // Team 2 Variables
        Player *m_team2[MAX_PLAYERS];
        int m_numTeam2;
        int m_score2;

        // Base Point Value
        int m_pointValue;
};

// Key:
//  A/a: Assist
//  B/b: Block (TODO)
//  R/r: Rebound
//  S/s: Steal
//  T/t: Turnover
//  P/p: 1/2-Pointer
//  Q/q: 2/3-Pointer
//  F/f: Field Goal Attempt
//
//  M/m: Open Menu
//  E/e: Exit
class BallegeStatTracker {
    public: 

        // Constructor
        BallegeStatTracker() {

            // Prompt and receive user input for desired mode
            int mode;
            std::cout << "Please select a mode (1 or 2): ";
            std::cin >> mode;
            std::cin.ignore();

            // Create new stat board
            m_board = new Statboard(mode);
        }

        BallegeStatTracker(int mode, std::string team1[], std::string team2[]) {
            
            // Create new stat board
            m_board = new Statboard(mode);

            // Add players to team 1
            for (int i = 0; i < MAX_PLAYERS; i++) {
                m_board->addPlayer(1, team1[i]);
            }

            // Add players to team 2
            for (int j = 0; j < MAX_PLAYERS; j++) {
                m_board->addPlayer(2, team2[j]);
            }
        }

        // Main loop function of the program
        void run() {

            while(1) {
                // Display board
                m_board->printBoard();
                std::cout << std::endl;

                // Display key
                printKey();
                std::cout << std::endl;

                // Prompt and receive user input
                std::string input;
                std::cout << "Stat string: ";
                getline(std::cin, input);

                // Handle return code
                // Return Codes:
                //  0: Continue program
                //  1: Exit program
                //  2: New game
                int returnCode = parse(input);
                switch (returnCode){
                    case 0:
                        break;
                    case 1:
                        return;
                    case 2:
                        newGame();
                        break;
                }
            }
        }

        // Parses user input
        bool parse(const std::string input) {

            // Variables for recording input parsings
            int team = -1;
            int player = -1;
            char stat = 'x';
            int amt = 1;

            // Iterate through input from user
            std::string::const_iterator itr;
            for (itr = input.begin(); itr != input.end(); itr++) {

                if (isalpha(*itr)) {
                    switch(tolower(*itr)){
                        case 'm':
                            menu();
                            break;
                        case 'n':
                            newGame();
                            return 2;
                        case 'e':
                            return 1;
                        default:
                            stat = *itr;
                            break;
                    }
                } else if (isdigit(*itr)) {
                    if (team == -1) {
                        team = *itr - '0';
                    } else if (player == -1) {
                        player = *itr - '0';
                    } else {
                        std::cout << "Invalid string." << std::endl;
                        break;
                    }
                } else {
                    if (*itr == ',') {
                        team = -1;
                        player = -1;
                        stat = 'x';
                        amt = 1;
                        continue;
                    }

                    if (*itr == '-') {
                        team = -1;
                        player = -1;
                        stat = 'x';
                        amt = -1;
                        continue;
                    }
                }

                if ((team != -1) && (player != -1) && (stat != 'x')) {
                    std::cout << team << player << stat << amt;
                    updateBoard(team, player, stat, amt);
                }
            }

            return 0;
        }

        // Sends updates to the board as prompted
        void updateBoard(int team, int player, char stat, int amt) {
            switch(stat) {
                case 'a':
                    m_board->editAssists(team, player, amt);
                    break;
                case 'r':
                    m_board->editRebounds(team, player, amt);
                    break;
                case 's':
                    m_board->editSteals(team, player, amt);
                    break;
                case 't':
                    m_board->editTurnovers(team, player, amt);
                    break;
                case 'p':
                    m_board->editPm(team, player, amt);
                    m_board->editFgm(team, player, amt);
                    m_board->editFga(team, player, amt);
                    break;
                case 'q':
                    m_board->editPm3(team, player, amt);
                    m_board->editFgm(team, player, amt);
                    m_board->editFga(team, player, amt);
                    break;
                case 'f':
                    m_board->editFga(team, player, amt);
                    break;
                default:
                    std::cout << "Invalid character." << std::endl;
                    break;
            }
        }

        // Menu for editing players
        // Menu Commands:
        //  A/a: Add player
        //  E/e: Edit player
        //  R/r: Remove player
        //  S/s: Switch players
        //  X/x: Exit
        void menu() {
            bool menuFlag = true;
            while (menuFlag) {

                // Prompt and receive user input
                std::string command;
                std::cout << "Enter menu command: ";
                getline(std::cin, command);

                // Parse menu input
                std::string::const_iterator itr;
                for (itr = command.begin(); itr != command.end(); itr++) {
                    switch(tolower(*itr)) {
                        case 'a':
                            addPlayer();
                            break;
                        case 'x':
                            menuFlag = false;
                            break;
                        default:
                            std::cout << "Invalid menu command." << std::endl;
                    }
                }
            }
        }

        // Starts a new stat board
        void newGame() {

            // Delete old stat board
            delete m_board;

            // Prompt and receive user input for desired mode
            int mode;
            std::cout << "Please select a mode (1 or 2): ";
            std::cin >> mode;
            std::cin.ignore();

            // Create new stat board
            m_board = new Statboard(mode);
        }

        // Add player to stat board
        void addPlayer() {

            // Prompt and receive user input for desired team
            int team = -1;
            std::cout << "Please select a team (1 or 2): ";
            std::cin >> team;
            
            // Prompt and receive user input for desired name
            std::cin.ignore();
            std::string name;
            std::cout << "Please enter a name (Recommend 10 no more than characters): ";
            getline(std::cin, name);

            // Add player
            m_board->addPlayer(team, name);
        }

        /* --- Auxiliary Functions --- */

        // Prints program key
        // Key:
        //  A/a: Assist
        //  B/b: Block
        //  R/r: Rebound
        //  S/s: Steal
        //  T/t: Turnover
        //  P/p: 1/2-Pointer
        //  Q/q: 2/3-Pointer
        //  F/f: Field Goal Attempt
        //
        //  M/m: Open Menu
        //  N/n: New Game
        //  E/e: Exit
        void printKey() {
            std::cout << std::setfill(' ');
            std::cout << "Key:" << std::endl;
            std::cout << std::setw(3) << "" << "A/a: Assist" << std::endl;
            std::cout << std::setw(3) << "" << "R/r: Rebound" << std::endl;
            std::cout << std::setw(3) << "" << "S/s: Steal" << std::endl;
            std::cout << std::setw(3) << "" << "T/t: Turnover" << std::endl;
            std::cout << std::setw(3) << "" << "P/p: 1/2 Pointer" << std::endl;
            std::cout << std::setw(3) << "" << "Q/q: 2/3 Pointer" << std::endl;
            std::cout << std::setw(3) << "" << "F/f: Field Goal Attempt" << std::endl << std::endl;

            std::cout << std::setw(3) << "" << "M/m: Open Menu" << std::endl;
            std::cout << std::setw(3) << "" << "E/e: Exit" << std::endl;
        }

    private:
        Statboard *m_board;
};

int main() {

    std::string team1[5] = {
        "Jason",
        "John",
        "Kent",
        "Nathan",
        "Ryan"
    };

    std::string team2[5] = {
        "Gideon",
        "Justin",
        "Kalani",
        "Kaison",
        "Vincent"
    };
    
    BallegeStatTracker b = BallegeStatTracker(1, team1, team2);

    b.run();

    return 0;
}