# include <Siv3D.hpp> // OpenSiv3D v0.6.8

class PieceImages {
	using TextureT = std::unique_ptr<Texture>;
public:
	PieceImages() :
		BLACKKING(new Texture{ U"../images/pieces/black/king.png" }),
		BLACKQUEEN(new Texture{ U"../images/pieces/black/queen.png" }),
		BLACKBISHOP(new Texture{ U"../images/pieces/black/bishop.png" }),
		BLACKKNIGHT(new Texture{ U"../images/pieces/black/knight.png" }),
		BLACKROOK(new Texture{ U"../images/pieces/black/rook.png" }),
		BLACKPAWN(new Texture{ U"../images/pieces/black/pawn.png" }),
		WHITEKING(new Texture{ U"../images/pieces/white/king.png" }),
		WHITEQUEEN(new Texture{ U"../images/pieces/white/queen.png" }),
		WHITEBISHOP(new Texture{ U"../images/pieces/white/bishop.png" }),
		WHITEKNIGHT(new Texture{ U"../images/pieces/white/knight.png" }),
		WHITEROOK(new Texture{ U"../images/pieces/white/rook.png" }),
		WHITEPAWN(new Texture{ U"../images/pieces/white/pawn.png" })
	{}
	const TextureT BLACKKING;
	const TextureT BLACKQUEEN;
	const TextureT BLACKBISHOP;
	const TextureT BLACKKNIGHT;
	const TextureT BLACKROOK;
	const TextureT BLACKPAWN;
	const TextureT WHITEKING;
	const TextureT WHITEQUEEN;
	const TextureT WHITEBISHOP;
	const TextureT WHITEKNIGHT;
	const TextureT WHITEROOK;
	const TextureT WHITEPAWN;
};

enum class Piece
{
	NONE,          //  0
	WHITEKING,     //  1
	WHITEQUEEN,    //  2
	WHITEBISHOP,   //  3
	WHITEKNIGHT,   //  4
	WHITEROOK,     //  5
	WHITEPAWN,     //  6
	BLACKKING,     //  7
	BLACKQUEEN,    //  8
	BLACKBISHOP,   //  9
	BLACKKNIGHT,   // 10
	BLACKROOK,     // 11
	BLACKPAWN,     // 12
};

void Main()
{
	Scene::SetBackground(Color{ 200, 200, 200 });
	Window::Resize(800, 600);
	constexpr int Tilesize = 50;
	int i, j;
	constexpr int boardstart[8][8] = { {11, 10, 9, 8, 7, 9, 10, 11},
						               {12, 12, 12, 12, 12, 12, 12, 12},
						               {0, 0, 0, 0, 0, 0, 0, 0},
						               {0, 0, 0, 0, 0, 0, 0, 0},
						               {0, 0, 0, 0, 0, 0, 0, 0},
						               {0, 0, 0, 0, 0, 0, 0, 0},
						               {6, 6, 6, 6, 6, 6, 6, 6},
					   	               {5, 4, 3, 2, 1, 3, 4, 5},
	};

	Piece board[8][8];
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			board[j][i] = (Piece)boardstart[j][i];
		}
	}

	PieceImages image{};

	while (System::Update())
	{
		for (i = 0; i < 8; i++) {
			for (j = 0; j < 8; j++) {
				Rect hoge = Rect(200 + Tilesize * i, 100 + Tilesize * j, Tilesize, Tilesize);
				if ((i + j) % 2 == 0) {
					hoge.draw(Palette::Lightsalmon);
				}
				else{
					hoge.draw(Palette::Chocolate);
				}
				switch (board[j][i])
				{
				case Piece::WHITEKING:
					image.WHITEKING.get()->drawAt(200 + Tilesize * i + Tilesize / 2, 100 + Tilesize * j + Tilesize / 2);
					break;
				case Piece::WHITEQUEEN:
					image.WHITEQUEEN.get()->drawAt(200 + Tilesize * i + Tilesize / 2, 100 + Tilesize * j + Tilesize / 2);
					break;
				case Piece::WHITEBISHOP:
					image.WHITEBISHOP.get()->drawAt(200 + Tilesize * i + Tilesize / 2, 100 + Tilesize * j + Tilesize / 2);
					break;
				case Piece::WHITEKNIGHT:
					image.WHITEKNIGHT.get()->drawAt(200 + Tilesize * i + Tilesize / 2, 100 + Tilesize * j + Tilesize / 2);
					break;
				case Piece::WHITEROOK:
					image.WHITEROOK.get()->drawAt(200 + Tilesize * i + Tilesize / 2, 100 + Tilesize * j + Tilesize / 2);
					break;
				case Piece::WHITEPAWN:
					image.WHITEPAWN.get()->drawAt(200 + Tilesize * i + Tilesize / 2, 100 + Tilesize * j + Tilesize / 2);
					break;
				case Piece::BLACKKING:
					image.BLACKKING.get()->drawAt(200 + Tilesize * i + Tilesize / 2, 100 + Tilesize * j + Tilesize / 2);
					break;
				case Piece::BLACKQUEEN:
					image.BLACKQUEEN.get()->drawAt(200 + Tilesize * i + Tilesize / 2, 100 + Tilesize * j + Tilesize / 2);
					break;
				case Piece::BLACKBISHOP:
					image.BLACKBISHOP.get()->drawAt(200 + Tilesize * i + Tilesize / 2, 100 + Tilesize * j + Tilesize / 2);
					break;
				case Piece::BLACKKNIGHT:
					image.BLACKKNIGHT.get()->drawAt(200 + Tilesize * i + Tilesize / 2, 100 + Tilesize * j + Tilesize / 2);
					break;
				case Piece::BLACKROOK:
					image.BLACKROOK.get()->drawAt(200 + Tilesize * i + Tilesize / 2, 100 + Tilesize * j + Tilesize / 2);
					break;
				case Piece::BLACKPAWN:
					image.BLACKPAWN.get()->drawAt(200 + Tilesize * i + Tilesize / 2, 100 + Tilesize * j + Tilesize / 2);
					break;
				}
			}
		}
	}
}
