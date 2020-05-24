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

class Card {
public:
    enum cardRank {ACE=1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN=10, JACK=10, QUEEN=10, KING=10 };
    enum cardSuit {HEART, DIAMOND, CLUB, SPADE};
    Card (cardRank r, cardSuit s, bool f) : rank(r), suit (s), faceup(f) {}
    void Flip() {
        faceup = !faceup;
    }
    int GetValue() const {
        return static_cast<int>(rank);
    }
private:
    cardRank rank;
    cardSuit suit;
    bool faceup;
};

int main()
{
    Card threeHeart(Card::THREE, Card::HEART, UP);
    cout<<threeHeart.GetValue()<<endl;

    Card aceSpade(Card::ACE, Card::SPADE, DOWN);
    cout<<aceSpade.GetValue()<<endl;
}
