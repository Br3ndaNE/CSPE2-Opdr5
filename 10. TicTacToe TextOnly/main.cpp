// #include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <memory>



class TicTacToeModel{
	private:
		std::vector<std::pair<int, int>> moves;
		int playerBool = 0; // player 0 is x; player 1 is o
		int WinningInt = 0;
		char board[3][3] = {
			{'.','.','.'},
			{'.','.','.'},
			{'.','.','.'}
		};


	public:
		TicTacToeModel(){}		

		char (*GetBoard())[3] {
				return board;
		}

		int getWinningInt(){
			return WinningInt;
		}

		void ValidMove(int x, int y){
			if(board[x][y] == '.' && playerBool == 0){
				playerBool = 1;

				board[x][y] = 'x';

				if(CheckFinishedPlayer('x', 1) == 1){
					WinningInt = 1;
				}
				moves.push_back({x,y});
			}
			else if(board[x][y] == '.' && playerBool == 1){
				playerBool = 0;

				board[x][y] = 'o';

				if(CheckFinishedPlayer('o', 2) == 2){
					WinningInt = 2;
				}
				moves.push_back({x,y});
			}
			else{
				std::cout << "invalid move" << std::endl;
			}
		}

		void Undo(){
			if(!moves.empty()){
				auto lastPair = moves.back();
				board[lastPair.first][lastPair.second] = '.';

				if(playerBool == 0){
					playerBool = 1;
				}else{
					playerBool = 0
				}

				moves.pop_back();
			}else{
				std::cout << "Nothing to undo" <<std::endl;
			}
			
			
		}

		int CheckFinishedPlayer(char player, int returnOnWin){
			for(int i = 0; i <= 2; i++){
				// horizontaal
				if( board[i][0] == player && board[i][1] == player && board[i][2] == player ){
					return returnOnWin;
				}
				// verticaal
				if( board[0][i] == player && board[1][i] == player && board[2][i] == player ){
					return returnOnWin;
				}
				// diagonaal
				if( board[0][0] == player && board[1][1] == player && board[2][2] == player){return returnOnWin;}
				if( board[2][0] == player && board[1][1] == player && board[0][2] == player){return returnOnWin;}
			}
			return 0;
		}
};

class TicTacToeView{
	private:
		
	public:
		TicTacToeView(){}
   		 void DisplayBoard(char board[3][3]) {
			std::cout << std::endl;
			for (int i = 2; i >= 0; i--) {
				for (int j = 0; j < 3; j++) {
					std::cout << board[i][j] << " ";
				}
				std::cout << std::endl;
			}
			std::cout << std::endl;
    	}
};

class Command{
	public:
		virtual void Execute() = 0;
		virtual void Undo() = 0;
};

class MoveCommand : public Command{
	private:
    TicTacToeModel& model; 
    int x;
    int y;

	public:
    MoveCommand(TicTacToeModel& model, int x, int y) : 
        model(model), x(x), y(y) 
    {}

	void Execute() override{
		model.ValidMove(x, y);
	}

	void Undo() override{
		model.Undo();
	}
};

class TicTacToeControl{
	private:
		TicTacToeModel& model;
		TicTacToeView& view;
		std::vector<std::unique_ptr<Command>> commandHistory;
	public:
		TicTacToeControl(TicTacToeModel& model, TicTacToeView& view) : 
			model(model), 
			view(view)
		{}

		void executeCommand(std::unique_ptr<Command> cmd){
			cmd->Execute();
			commandHistory.push_back(std::move(cmd));
		}

		void undoCommand(){
			if(!commandHistory.empty()){
				commandHistory.back()->Undo();
				commandHistory.pop_back();
			}else{
				std::cout << "No moves to undo!";
			}
		}

};


class Game{

	private:
	TicTacToeModel& model;
	TicTacToeView& view;
	TicTacToeControl& controller;
	int var_x;
	int var_y;
	int undoChar;
	
	public:
	Game(TicTacToeModel& model, TicTacToeView& view, TicTacToeControl& controller) : 
		model(model), 
		view(view), 
		controller(controller) 
	{}

	int play() {
		view.DisplayBoard(model.GetBoard());
		if(model.getWinningInt() == 1){
			return 1;
		}
		if(model.getWinningInt() == 2){
			return 2;
		}

		std::cout << "Undo? 1/0";
		std::cin >> undoChar;

		if(undoChar == 1){
			controller.undoCommand();
			return 0;
		}
		else{
			std::cout << "X: ";
			std::cin >> var_x;
			std::cout << "Y: ";
			std::cin >> var_y;
			controller.executeCommand(std::make_unique<MoveCommand>(model,var_y,var_x));
			return 0;
		}
	}
};






int main( int argc, char *argv[] ){
	TicTacToeView view;
	TicTacToeModel model;
	TicTacToeControl controller(model,view);
	Game TTT(model,view,controller);
	for(;;){
		int winState = TTT.play();
		if(winState == 1){std::cout << "x Won" << std::endl; return 0;}
		if(winState == 2){std::cout << "o Won" << std::endl; return 0;}
	}

}

