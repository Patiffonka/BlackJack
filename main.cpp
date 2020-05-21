/*
 * BlacJack
 *
 * Kulisov Sergey
 *
 * QT Creator v.4.11.0
 *
 */

#include <iostream>
#define UP true
#define DOWN false

using namespace std;

enum cardRank {ACE=1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
enum cardSuit {HEART, DIAMOND, CLUB, SPADE};

class Card {
private:
    cardRank rank;
    cardSuit suit;
    bool faceup;
public:
    Card (cardRank r, cardSuit s, bool f) : rank(r), suit (s), faceup(f) {}
    void Flip() {
        faceup = !faceup;
    }
    int GetValue() const {
        return static_cast<int>(rank);
    }

};

int main()
{
    Card threeHeart(THREE, HEART, UP);
    cout<<threeHeart.GetValue()<<endl;

    Card aceSpade(ACE, SPADE, DOWN);
    cout<<aceSpade.GetValue()<<endl;
}
