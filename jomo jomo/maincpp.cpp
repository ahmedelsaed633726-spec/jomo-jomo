#include <SFML/Graphics.hpp>
#include <cmath>

using namespace sf;

int main() {
    RenderWindow window(VideoMode(1200, 700), "One Piece - Luffy Birds");
    window.setFramerateLimit(60);

    // 1. تعريف لوفي (القذيفة)
    CircleShape luffy(25.f);
    luffy.setFillColor(Color::Red); // ده لوفي الأساسي قبل الجرافيكس
    luffy.setOrigin(25.f, 25.f);
    Vector2f slingPos(200.f, 500.f); // مكان المنجنيق
    luffy.setPosition(slingPos);

    // 2. متغيرات الحركة والفيزياء
    Vector2f velocity(0.f, 0.f);
    float gravity = 0.5f;
    bool isDragging = false;
    bool isLaunched = false;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) window.close();

            // مسك لوفي بالماوس
            if (event.type == Event::MouseButtonPressed && !isLaunched) {
                if (luffy.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    isDragging = true;
                }
            }

            // إطلاق لوفي
            if (event.type == Event::MouseButtonReleased && isDragging) {
                isDragging = false;
                isLaunched = true;
                // القوة = المسافة بين السحب والمركز * سرعة معينة
                velocity = (slingPos - luffy.getPosition()) * 0.15f;
            }
        }

        // منطق السحب (Drag)
        if (isDragging) {
            Vector2i mousePos = Mouse::getPosition(window);
            luffy.setPosition(Vector2f(mousePos.x, mousePos.y));
        }

        // منطق الطيران (Physics)
        if (isLaunched) {
            velocity.y += gravity; // تأثير الجاذبية
            luffy.move(velocity);

            // لو لمس الأرض يقف (مؤقتاً)
            if (luffy.getPosition().y > 650) {
                isLaunched = false;
                luffy.setPosition(slingPos); // يرجع للمنجنيق تاني للتجربة
                velocity = Vector2f(0, 0);
            }
        }

        window.clear(Color(135, 206, 235)); // لون السما

        // رسم المنجنيق (بسيط)
        RectangleShape sling(Vector2f(10, 150));
        sling.setPosition(slingPos.x - 5, slingPos.y);
        sling.setFillColor(Color(100, 50, 0));

        window.draw(sling);
        window.draw(luffy);
        window.display();
    }
    return 0;
}