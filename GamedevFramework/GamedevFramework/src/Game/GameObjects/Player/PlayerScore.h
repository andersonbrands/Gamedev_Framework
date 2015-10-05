/***************************************************************************************
*	Title: PlayerScore.h
*	Author: Brandao, Anderson
*	Date: 2015
*
***************************************************************************************/

#ifndef PLAYER_SCORE_H_
#define PLAYER_SCORE_H_

#include <vector>
#include "../../../Framework/Renderer/Sprite/Sprite.h"


using namespace Framework;
using namespace std;

class PlayerScore {
    private:
        int score_;
        Sprite* label_;
        vector<Sprite*> numbers_;

        Sprite* getNumberSprite(int n) const;

    public:
        PlayerScore();
        virtual		~PlayerScore();
        void		init();
        void		set(int score) {
            if (score >= 1000000) {
                score_ = 999999;
            } else {
                score_ = score;
            }
        }
        int			get() const {
            return score_;
        }
        void		render() const;
};

#endif // PLAYER_SCORE_H_
