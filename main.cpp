/*
 * BlacJack
 *
 * Kulisov Sergey
 *
 * QT Creator v.4.11.0
 *
 */

#include <iostream>
#include <vector>
#include <string>
#define UP true
#define DOWN false

using namespace std;

class Card {
public:
    enum cardRank {ACE=1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
    enum cardSuit {HEART, DIAMOND, CLUB, SPADE};
    Card (cardRank r, cardSuit s, bool f) : rank(r), suit (s), faceup(f) {}
    void Flip() {
        faceup = !faceup;
    }
    int GetValue() const {
        int rankInt;
        if (rank == JACK || rank == QUEEN || rank == KING) rankInt = 10;
        else rankInt = static_cast<int>(rank);
        return rankInt;
    }
    cardRank getRank() const {return rank;}
    cardSuit getSuit() const {return suit;}
    bool faceUp() const {return faceup;}
    friend ostream& operator<<(ostream& out, const Card &date);

private:
    cardRank rank;
    cardSuit suit;
    bool faceup;
};

ostream& operator<<(ostream& out, const Card &date){
    if (date.faceUp()) {
    out << "|";
    switch (date.rank) {
        case Card::ACE: out << "A"; break;
        case Card::TWO: out << "2"; break;
        case Card::THREE: out << "3"; break;
        case Card::FOUR: out << "4"; break;
        case Card::FIVE: out << "5"; break;
        case Card::SIX: out << "6"; break;
        case Card::SEVEN: out << "7"; break;
        case Card::EIGHT: out << "8"; break;
        case Card::NINE: out << "9"; break;
        case Card::TEN: out << "10"; break;
        case Card::JACK: out << "J"; break;
        case Card::QUEEN: out << "Q"; break;
        case Card::KING: out << "K"; break;
    }
    out << " ";
    switch (date.suit) {
        case Card::HEART: out << "heart"; break;
        case Card::DIAMOND: out << "diamond"; break;
        case Card::CLUB: out << "club"; break;
        case Card::SPADE: out << "spade"; break;
    }
    out << "| " << flush;
    }
    else out << "|XXXX| " << flush;
    return out;
}

class Hand {
private:
    vector<Card*> hand;
public:
    void add(Card* c) {hand.push_back(c);}
    void clear(){
        for (unsigned int i = 0; i < hand.size(); ++i) delete hand[i];
        hand.clear();
        }
    unsigned int size() const {return hand.size();}
    int getValue() const{
        int sum=0;
        for (unsigned int i = 0; i < hand.size(); ++i){
            if (hand.at(i)->getRank() == Card::ACE && ((sum+11)<21)) sum+=11;
            else sum+=hand.at(i)->GetValue();
        }
        return sum;
    }
    void print() {
        for (unsigned int i = 0; i < hand.size(); ++i)
        {
            cout << hand[i]->GetValue() << endl;
        }
        cout << "sum: " << getValue() << endl;
    }
    vector<Card*> getHand() const {return hand;}
};

class GenericPlayer: public Hand {
private:
    string name;
public:
    GenericPlayer(string n) : Hand(), name(n){}
    virtual ~GenericPlayer(){}
    virtual bool isHitting() const {return true;}                          //???
    bool IsBoosted(){
        if (getValue()>21) return true;
        else return false;
    }
    void Bust(){
        cout << "Player " << name << ": Bust!" << endl;
    }
    string getName() const {return name;}
    friend ostream& operator<<(ostream& out, const GenericPlayer &player);
};

ostream& operator<<(ostream& out, const GenericPlayer &player){
    out << "Player " << player.name << ": ";
    for (unsigned int i=0; i < player.getHand().size(); ++i ){
        out << *player.getHand()[i];
    }
    out << "\nSum: " << player.getValue() << endl;
    return out;
}

class Player: public GenericPlayer {
public:
    Player(string n) : GenericPlayer(n){}
//    virtual ~Player();
    virtual bool isHitting() const {
        cout << getName() << ", do you want a hit? (Y/N): ";
        char answer;
        cin >> answer;
        return (answer == 'Y' || answer == 'y');
    }
    void win() const {
        cout << "Player " << getName() << " win!" << endl;
    }
    void lose() const {
        cout << "Player " << getName() << " lose!" << endl;
    }
    void push() const {
        cout << "Player " << getName() << " push!" << endl;
    }


};

class House: public GenericPlayer {
public:
    House(string name = "House"): GenericPlayer(name){}
    virtual bool IsHitting() const {
        return ((getValue()<16) ? true : false);
    }
    void FlipFirstCard(){
        if (!getHand().empty()) getHand()[0]->Flip();
        else cout << "hand is empty" << endl;
    }
};

int main()
{
    Card KINGDIAMOND(Card::KING, Card::DIAMOND, UP);
    Card ACEHEART(Card::ACE, Card::HEART, UP);
    Card TWOSPADE(Card::TWO, Card::SPADE, UP);
    Card EIGHTCLUB(Card::EIGHT, Card::CLUB, UP);
    cout << TWOSPADE << endl;
    GenericPlayer VASYAN("Vasyan");
    TWOSPADE.Flip();
    VASYAN.add(&KINGDIAMOND);
    VASYAN.add(&ACEHEART);
    VASYAN.add(&TWOSPADE);
    VASYAN.add(&EIGHTCLUB);
    cout << VASYAN << endl;
    GenericPlayer SERYOGA("Seryoga");
    SERYOGA.add(&KINGDIAMOND);
}
