#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
#include <Windows.h>
#pragma comment(lib, "Winmm.lib")
#include <mmsystem.h>

// Define all the constant variables
#define PLAYER_DAMAGE 150
#define SWORD_MULTIPLIER 1.4
#define MAGIC_MULTIPLIER 2
#define MAX_MAGIC_ATTACKS 3
#define bossHealthMultiplier 1.4


using namespace std;

/**
 * The function "nameRandomizer" returns a random name from a predefined list of names.
 *
 * @return a randomly selected name from the array "names".
 */
string nameRandomizer() {
    string names[10] = { "Tilin", "Bowser Jr", "Adria", "Javier", "Carmen", "Roberto", "Ramon", "Super Tilin", "Nicolas Maduro","Javier Jr" };
    int num = rand() % 10;
    return names[num];
}

/**
 * The function initializes various game variables such as player health, enemy health, magic attacks
 * left, and boss health, and prompts the user to input their username.
 *
 * @param playerName The name of the player.
 * @param playerHealth The current health of the player.
 * @param maxPlayerHealth The maximum health of the player character.
 * @param enemyHealth The enemy's current health.
 * @param maxEnemyHealth The maximum health of the enemy in the game.
 * @param magicAttacksLeft The `magicAttacksLeft` parameter represents the number of magic attacks the
 * player has remaining.
 * @param bossHealth The bossHealth parameter represents the current health of the boss in the game.
 * @param bossName The name of the boss in the game.
 * @param enemyName The enemy's name in the game.
 * @param maxBossHealth The maximum health of the boss in the game.
 */

void initializeGame(string& playerName, int& playerHealth, int& maxPlayerHealth, int& enemyHealth, int& maxEnemyHealth, int& magicAttacksLeft, int& bossHealth, string& bossName, string& enemyName, int& maxBossHealth) {
    srand(time(nullptr));
    playerHealth = 500;
    maxPlayerHealth = playerHealth;
    enemyHealth = 700;
    bossHealth = bossHealthMultiplier * enemyHealth;
    maxBossHealth = bossHealth;
    maxEnemyHealth = enemyHealth;
    magicAttacksLeft = MAX_MAGIC_ATTACKS;
    enemyName = nameRandomizer();
    cout << "Insert your username: ";
    cin >> playerName;
    system("cls");
    bossName = nameRandomizer();
}

int critic(int attack) {
    double criticProbability = 0.3;
    double randomProbability = static_cast<double>(rand()) / RAND_MAX;
    if (randomProbability < criticProbability) {
        return (attack * 3);
    }
    return attack;
}
/**
 * The function "selectEnemy" allows the user to select an enemy to fight based on their health and
 * name.
 *
 * @param enemyHealth The parameter "enemyHealth" represents the health of the regular enemy.
 * @param bossHealth The parameter "bossHealth" represents the health of the boss enemy.
 * @param enemyName The name of the regular enemy.
 * @param bossName The `bossName` parameter is a string that represents the name of the boss enemy.
 *
 * @return an integer value, which represents the selected enemy.
 */

int selectEnemy(int enemyHealth, int bossHealth, string enemyName, string bossName) {
    int op;
    string bossNameValidate = "Nicolas Maduro";
    size_t maxBossName = max(bossName.length(), bossNameValidate.length());
    size_t maxEnemyName = max(enemyName.length(), bossNameValidate.length());

    enemyName.resize(maxEnemyName, ' ');
    bossName.resize(maxBossName, ' ');
    while (true) {
        if (enemyHealth > 0 && bossHealth > 0) {
            cout << "#######################" << endl;
            cout << "#                     #" << endl;
            cout << "#   Select a enemy    #" << endl;
            cout << "#  1. " << enemyName << "  #" << endl;
            cout << "#  2. " << bossName << "  #" << endl;
            cout << "#                     #" << endl;
            cout << "#######################" << endl;
            cin >> op;
            system("cls");

            if (op > 0 && op <= 2) {
                return op;
            }
        }
        else if (enemyHealth > 0) {
            cout << "#######################" << endl;
            cout << "#                     #" << endl;
            cout << "#   Select a enemy    #" << endl;
            cout << "#  1. " << enemyName << "  #" << endl;
            cout << "#                     #" << endl;
            cout << "#######################" << endl;
            cin >> op;
            system("cls");
            if (op == 1) return op;
        }
        else {
            cout << "#######################" << endl;
            cout << "#                     #" << endl;
            cout << "#   Select a enemy    #" << endl;
            cout << "#  1. " << bossName << "  #" << endl;
            cout << "#                     #" << endl;
            cout << "#######################" << endl;
            cin >> op;
            system("cls");
            if (op == 1) return (op+1);
        }
    }
}

int generateRandomEnemyAttack() {
    return (10 + rand() % (51 - 10));
}
/**
 * The function allows the player to select a type of attack (sword, magic, or punch) and returns the
 * chosen attack type.
 *
 * @param magicAttacksLeft The number of magic attacks the player has left.
 * @param enemyHealth The current health of the enemy.
 * @param bossHealth The parameter "bossHealth" represents the current health of the boss in the game.
 * @param enemyName The parameter "enemyName" is a string that represents the name of the enemy.
 * @param bossName The parameter "bossName" is a string that represents the name of the boss character.
 *
 * @return the type of attack selected by the player.
 */
int selectPlayerAttack(int magicAttacksLeft, int& enemyHealth, int & bossHealth, string enemyName, string bossName) {
    int typeAttack;
    while (true) {
        cout << "" << endl;
        cout << "" << endl;
        cout << "#############################" << endl;
        cout << "#                           #" << endl;
        cout << "#  Select a type of attack  #" << endl;
        cout << "#  1. Sword                 #" << endl;
        cout << "#  2. Magic                 # (" << magicAttacksLeft << " left)" << endl;
        cout << "#  3. Punch                 #" << endl;
        cout << "#                           #" << endl;
        cout << "#############################" << endl;
        cin >> typeAttack;
        system("cls");

        if (typeAttack == 2 && magicAttacksLeft <= 0) {
            cout << "You have no more magic attacks left." << endl;
        }
        else if (typeAttack >= 1 && typeAttack <= 3) {
            return typeAttack;
        }
    }
}

/**
 * The function "playerAttack" takes in the type of attack, enemy health, and maximum enemy health, and
 * returns the updated enemy health after the player's attack.
 *
 * @param typeAttack The type of attack the player wants to use. It can be 1 for a sword attack, 2 for
 * a magic attack, or 3 for a regular attack.
 * @param enemyHealth The current health of the enemy. It is an integer value representing the amount
 * of health the enemy has remaining.
 * @param maxEnemyHealth The maximum health of the enemy.
 *
 * @return the updated enemyHealth after the player's attack.
 */

int playerAttack(int typeAttack, int enemyHealth, int maxEnemyHealth) {
    int damage = PLAYER_DAMAGE;
    switch (typeAttack) {
    case 1:
        enemyHealth -= PLAYER_DAMAGE * SWORD_MULTIPLIER;
        return enemyHealth;
    case 2:
        enemyHealth -= PLAYER_DAMAGE * MAGIC_MULTIPLIER;
        return enemyHealth;
    case 3:
        damage = critic(damage);
        enemyHealth -= damage;
        return enemyHealth;
    default:
        return enemyHealth;
    }
}

/**
 * The function displays the enemy's attack message and the player's current health.
 *
 * @param enemyAttack The amount of damage the enemy has done to the player.
 * @param playerHealth The current health of the player.
 * @param maxPlayerHealth The maximum health of the player.
 *
 * @return the updated playerHealth value.
 */

int displayEnemyMessage(int enemyAttack, int playerHealth, int maxPlayerHealth) {
    string playerHealthStr = to_string(playerHealth);
    string maxplayerHealthStr = to_string(maxPlayerHealth);


    if (playerHealth <= 0) {
        playerHealth = 0;
        playerHealthStr = to_string(playerHealth);
    }
     
    size_t maxPlayerHealthlength = max(playerHealthStr.length(), maxplayerHealthStr.length());
    playerHealthStr.resize(maxPlayerHealthlength, ' ');


    cout << "#          The enemy has done " << enemyAttack << " points of damage.      #" << endl;
    cout << "#         Now you have: " << playerHealthStr << " | " << maxPlayerHealth << " Health.               #" << endl;

    return playerHealth;
}


/**
 * The function displays a message about a player's attack on an enemy, including the type of attack,
 * the enemy's health before and after the attack, and whether the enemy was killed.
 *
 * @param typeAttack The type of attack the player used (e.g. "Magic attack", "Sword attack", etc.)
 * @param enemyHealth The current health of the enemy.
 * @param enemyHealthPrevious The parameter `enemyHealthPrevious` represents the previous health value
 * of the enemy before the attack.
 * @param enemyName The name of the enemy that the player is attacking.
 */

void displayPlayerAttackMessage(string typeAttack, int enemyHealth, int enemyHealthPrevious, string enemyName) {
    if (enemyHealth <= 0) {
        enemyHealth = 0;
    }
    string enemyMax= "1000";
    string typeAttackMax = "Magic attack";
    string enemyHealthsi = to_string(enemyHealth);
    string enemyNameMax = "Nicolas Maduro";
    size_t max_length = max(enemyNameMax.length(), enemyName.length());
    size_t max_length_attack = max(typeAttack.length(), typeAttackMax.length());
    size_t maxEnemyHealth = max(enemyMax.length(), enemyHealthsi.length());

    enemyHealthsi.resize(maxEnemyHealth, ' ');
    enemyName.resize(max_length, ' ');
    typeAttack.resize(max_length_attack, ' ');

    cout << "#########################################################" << endl;
    cout << "#                                                       #" << endl;
    cout << "#      You've attacked your enemy with " << typeAttack << "     #" << endl;
    cout << "#                     " << enemyName << "                    #"  <<endl;
    cout << "#               Health: " << enemyHealthsi << " | " << enemyHealthPrevious << "                      #" << endl;
    if (enemyHealth == 0) {
        cout << "#               You killed " << enemyName << "               #" << endl;
    }
}



/**
 * The gameLoop function runs the main game loop, where the player and enemies take turns attacking
 * each other until either the player or all enemies are defeated.
 */




void gameLoop() {
    string playerName, bossName, enemyName;
    int playerHealth, maxPlayerHealth, enemyHealth, bossHealth, maxEnemyHealth, magicAttacksLeft, maxBossHealth;
    PlaySound(TEXT("background.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    initializeGame(playerName, playerHealth, maxPlayerHealth, enemyHealth, maxEnemyHealth, magicAttacksLeft, bossHealth, bossName, enemyName, maxBossHealth);


    while ((enemyHealth > 0  || bossHealth > 0 ) && playerHealth > 0) {
        int enemyAttack = generateRandomEnemyAttack();
        int typeAttack = selectPlayerAttack(magicAttacksLeft, enemyHealth, bossHealth, enemyName, bossName);

        if (typeAttack == 2) {
            magicAttacksLeft--; // Reducir el número de ataques mágicos disponibles
        }

        if (playerHealth > 0) {
            int op = selectEnemy(enemyHealth, bossHealth, enemyName, bossName);
            if (op == 1) {
                enemyHealth = playerAttack(typeAttack, enemyHealth, maxEnemyHealth);
                displayPlayerAttackMessage((typeAttack == 1 ? "Sword attack" : (typeAttack == 2 ? "Magic attack" : "Punch")), enemyHealth, maxEnemyHealth, enemyName);
            }
            else
            {
                bossHealth = playerAttack(typeAttack, bossHealth, maxBossHealth);
                displayPlayerAttackMessage((typeAttack == 1 ? "Sword attack" : (typeAttack == 2 ? "Magic attack" : "Punch")), bossHealth, maxBossHealth, bossName);
            }

            if (enemyHealth <= 0 && bossHealth <= 0) {
                size_t max = 15;
                playerName.resize(max, ' ');
                cout << "#                      "     <<playerName << "                  #"<< endl;
                cout << "#                      You won!                         #" << endl;
                cout << "#########################################################";
            }
        } else {
            cout << "You lost the game." << endl;
            break;
        }

        if (enemyHealth > 0 && bossHealth > 0 ) {
            playerHealth -= enemyAttack;
            displayEnemyMessage(enemyAttack, playerHealth, maxPlayerHealth);
            enemyAttack = generateRandomEnemyAttack();
            playerHealth -= enemyAttack;
            displayEnemyMessage(enemyAttack, playerHealth, maxPlayerHealth);
            if (playerHealth <= 0) {
                cout << "Game over." << endl;
            }
            cout << "#########################################################";
        }
        else if (enemyHealth > 0) {
            playerHealth -= enemyAttack;
            displayEnemyMessage(enemyAttack, playerHealth, maxPlayerHealth);
            if (playerHealth <= 0) {
                cout << "Game over." << endl;
            }
            cout << "#########################################################";
        }
        else if(bossHealth>0 )
        {
            playerHealth -= enemyAttack;
            displayEnemyMessage(enemyAttack, playerHealth, maxPlayerHealth);
            if (playerHealth <= 0) {
                cout << "Game over." << endl;
            }
            cout << "#########################################################";
        }
    }
}

int main() {
    gameLoop();
}