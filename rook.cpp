#include <QApplication>
#include "QMainWindow"
#include <QWidget>
#include "QPainter"
#include <QKeyEvent>
#include "QGridLayout"

class ChessBoardWidget: public QWidget
{
public:
    static constexpr int TILES = 8;

    void keyPressEvent(QKeyEvent* e) override
    {
        switch (e->key())
        {
            case Qt::Key_Up:
                rookY = std::max(rookY - 1, 0);
                break;
            case Qt::Key_Down:
                rookY = std::min(rookY + 1, TILES - 1);
                break;
            case Qt::Key_Left:
                rookX = std::max(rookX - 1, 0);
                break;
            case Qt::Key_Right:
                rookX = std::min(rookX + 1, TILES - 1);
                break;
        }
        update();
    }

    explicit ChessBoardWidget(QWidget *parent = nullptr) : QWidget(parent)
    {
        setMinimumSize(200, 200);
        setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        setFocusPolicy(Qt::StrongFocus);
    }

protected:
    void paintEvent(QPaintEvent *) override
    {

        QPainter painter(this);
        painter.fillRect(rect(), Qt::black);
        int tileSize = qMin(width(), height()) / TILES;
        int boardSize = tileSize * TILES;
        int xOffset = (width() - boardSize) / 2;
        int yOffset = (height() - boardSize) / 2;
        for (int row = 0; row < TILES; row++) {
            for (int col = 0; col < TILES; col++) {
                QColor color = (row + col) % 2 == 0 ? Qt::black : Qt::white;
                painter.fillRect(
                        xOffset + col * tileSize,
                        yOffset + row * tileSize,
                        tileSize, tileSize, color);
            }
        }
        painter.drawPixmap(xOffset + rookX * tileSize, yOffset + rookY * tileSize, tileSize, tileSize, rook);
    }

private:
    QPixmap rook = QPixmap("/Users/newowner/CLionProjects/chessbord with rook with qt/data/rook.png");

    int rookX = 0;
    int rookY = 0;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    auto *window = new QMainWindow;
    window->setWindowTitle("Chessboard with rook");
    window->resize(500, 500);

    auto *chessBoard = new ChessBoardWidget(window);
    window->setCentralWidget(chessBoard);

    window->show();

    return QApplication::exec();
}