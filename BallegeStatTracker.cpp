#include <string>

#define MAX_PLAYERS 10

class Player
{
    public:

        // Constructor
        Player(std::string name);

        // Modifier Functions 

        void changeName(std::string name) {
            m_name = name;
        }

        void editAssists(int num) {
            m_assists += num;
        }

        void editRebounds(int num) {
            m_rebounds += num;
        }

        void editSteals(int num) {
            m_steals += num;
        }

        void editTurnovers(int num) {
            m_turnovers += num;
        }

        void editPm(int num) {
            m_pm += num;
        }

        void editPm3(int num) {
            m_pm3 += num;
        }

        void editFgm(int num) {
            m_fgm += num;
        }

        void editFga(int num) {
            m_fga += num;
        }

        void editSm(int num) {
            m_sm += num;
        }

        void editSa(int num) {
            m_sa += num;
        }

        // Accessor Functions

        std::string getName() {
            return m_name;
        }

        int getAssists() {
            return m_assists;
        }

        int getRebounds() {
            return m_rebounds;
        }

        int getSteals() {
            return m_steals;
        }

        int getTurnovers() {
            return m_turnovers;
        }

        int getPm() {
            return m_pm;
        }

        int getPm3() {
            return m_pm3;
        }

        int getFgm() {
            return m_fgm;
        }

        int getFga() {
            return m_fga;
        }

        int getSm() {
            return m_sm;
        }

        int getSa() {
            return m_sa;
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

        // Field Goal Statistics
        int m_fgm;                        // Field Goals Made
        int m_fga;                        // Field Goals Attempted   

        // Shot Statistics
        int m_sm;                         // Shots Made
        int m_sa;                         // Shots Attempted
};

class Statboard
{
    public:

        // Constructor
        Statboard(int pointValue);

        // Destructor
        ~Statboard();

        // Player Functions

        void addPlayer(std::string name);
        void editPlayer(int player, std::string name);
        void removePlayer(int player);
        void switchPlayer(int p1, int p2);

        // Stat Functions
        
        void giveAssists(int player, int numAssists);
        void giveRebounds(int player, int numRebounds);
        void giveSteals(int player, int numSteals);
        void giveTurnovers(int player, int numTurnovers);
        void givePm(int player, int numPm);
        void givePm3(int player, int numPm3);
        void giveFgm(int player, int numFgm);
        void giveFga(int player, int numFga);
        void giveSm(int player, int numSm);
        void giveSa(int player, int numSa);

        void removeAssists(int player, int numAssists);
        void removeRebounds(int player, int numRebounds);
        void removeSteals(int player, int numSteals);
        void removeTurnovers(int player, int numTurnovers);
        void removePm(int player, int numPm);
        void removePm3(int player, int numPm3);
        void removeFgm(int player, int numFgm);
        void removeFga(int player, int numFga);
        void removeSm(int player, int numSm);
        void removeSa(int player, int numSa);

        // Board Functions

        void printBoard();
        void printHeader();

        // File Functions

        void exportBoard();

        // Modifier Functions

        void updatePointValue(int newPointValue) {
            m_pointValue = newPointValue;
        }

        // Accessor Functions

        int getPointValue() {
            return m_pointValue;
        }

    private:
        Player *m_players[MAX_PLAYERS];
        int m_pointValue;
};

class Game
{
    public:

        // Constructor
        Game(int mode);

        // Destructor
        ~Game();

        // Main Functions

        void nextGame();
        void displayGame();

        // File Functions

        void exportGame();

        // Modifier Functions

        void changeMode(int mode);

        // Accessor Functions

        int getMode() {
            return m_mode;
        }

    private:
        Statboard *m_board;
        int m_mode;
};

int main() {
    return 0;
}