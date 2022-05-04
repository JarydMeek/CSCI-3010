#include <iostream>
#include <string>

#include "Emotion.h"

int Emotion::counter_ = 0;

std::ostream& operator<<(std::ostream &os, const Emotion &d) {
    os << d.get_name();
    // TODO: print out more information if you want to
    return os;
}

Emotion* EmotionFactory::GetHappy() {
    return new Emotion("Happy", true, false, 1, 1, 1);
}
Emotion* EmotionFactory::GetSad() {
    return new Emotion("Sad", false, false, 0, 1, 1);
}
Emotion* EmotionFactory::GetAngry() {
    return new Emotion("Angry", true, false, 1, 1, 0);
}