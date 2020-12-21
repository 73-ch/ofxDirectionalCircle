#include "ofxDrawDirectionalCircle.h"

void ofxDrawDirectionalCircle(glm::vec2 frontPos, glm::vec2 backPos, float radius) {
    ofDrawCircle(frontPos, radius);
    const auto stretchedBackPos = backPos + (backPos - frontPos) * 1.2f;
    if(radius < glm::distance(frontPos, stretchedBackPos)) {
        const auto translatedBackPos = stretchedBackPos - frontPos;
        const auto m = radius * translatedBackPos;
        const auto norm = translatedBackPos.x * translatedBackPos.x + translatedBackPos.y * translatedBackPos.y;
        const auto radiusPerNorm = radius / norm;
        const auto n = std::sqrt(norm - radius * radius) * glm::vec2(translatedBackPos.y, -translatedBackPos.x);
        const auto a = radiusPerNorm * (m + n) + frontPos;
        const auto b = radiusPerNorm * (m - n) + frontPos;
        ofDrawTriangle(a, b, stretchedBackPos);
    }
}
