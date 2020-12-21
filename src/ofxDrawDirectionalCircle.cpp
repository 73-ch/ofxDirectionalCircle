#include "ofxDrawDirectionalCircle.h"

void ofxDrawDirectionalCircle(glm::vec2 frontPos, glm::vec2 backPos, float radius) {
    auto circleDir = glm::normalize(frontPos - backPos);
    auto crossVec = glm::vec2(circleDir.y, -circleDir.x);

    ofDrawTriangle(
        frontPos + crossVec * radius,
        frontPos + crossVec * -radius,
        backPos + (backPos - frontPos) * 1.2
    );
    ofDrawCircle(frontPos, radius);
}
