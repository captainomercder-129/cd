#include <Geode/Geode.hpp>
#include <Geode/modify/CCLabelBMFont.hpp>
#include <unordered_map>
#include <string>
using namespace geode::prelude;

static const std::unordered_map<std::string, std::string> TR = {
    {"Play", "Oyna"},
    {"Settings", "Ayarlar"},
    {"Options", "Secenekler"},
    {"Achievements", "Basarimlar"},
    {"Stats", "Istatistik"},
    {"Garage", "Garaj"},
    {"Search", "Ara"},
    {"Creator", "Yapimci"},
    {"Back", "Geri"},
    {"Resume", "Devam"},
    {"Exit", "Cikis"},
    {"Retry", "Tekrar"},
    {"Yes", "Evet"},
    {"No", "Hayir"},
    {"Cancel", "Iptal"},
    {"Download", "Indir"},
    {"Level Complete!", "Seviye Bitti!"},
    {"Attempt", "Deneme"}
};

static const char* tr(const char* s) {
    if (!s) return s;
    auto it = TR.find(s);
    return it != TR.end() ? it->second.c_str() : s;
}

class $modify(TrLabel, CCLabelBMFont) {
    void setString(const char* str, bool needsLayout) {
        CCLabelBMFont::setString(tr(str), needsLayout);
    }
    bool initWithString(const char* str, const char* fnt, float width,
                        CCTextAlignment align, CCPoint offset) {
        return CCLabelBMFont::initWithString(tr(str), fnt, width, align, offset);
    }
};
