#ifndef ConnectSupport_h
  #define ConnectSupport_h

  //hfiles they have function declarations as well as
  //enum and struct definitions

  void set_up(char*** board, int size_row, int size_col, int turns);
  char** make_board(int num_rows, int num_cols);
  void PlayGame(char** gameBoard, int size_row, int size_col, int turns,int win_num);
  int PutStep(char** gameBoard, int col, char piece, int size_row);
  void PrintBoard(char** cheeseBoard, int size_row, int size_col);
  bool is_valid_step(char** gameBoard, int player_col,int size_row);
  bool GameOver(char** gameBoard, int size_row, int size_col,int win_num, int playerRowStep, int playerColStep);
  bool IsWon(char** gameBoard, int size_row, int size_col, int win_num, int playerRowStep, int playerColStep);
  bool horz_win(char** board, int num_rows, int num_cols, int win_num, int playerRowStep, int playerColStep);
  bool vert_win(char** board, int num_rows, int num_cols, int win_num, int playerRowStep, int playerColStep);
  bool left_diag_win(char** board, int num_rows, int num_cols, int win_num, int playerRowStep, int playerColStep);
  bool IsTied(char** board, int num_rows, int num_cols,int win_num, int playerRowStep, int playerColStep);
  bool is_board_full(char** board, int num_rows, int num_cols);
  bool is_valid_formatting(int num_args_read, int num_args_needed);
  bool right_diag_win(char** board, int num_rows, int num_cols, int win_num, int playerRowStep, int playerColStep);


#endif
