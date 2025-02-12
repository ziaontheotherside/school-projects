"""
File:         py_match.py
Author:       Zia Animashaun
Date:         4/18/2022
Section:      Section 13
E-mail:       fanimas1@umbc.edu
Description:  A memory matching game where you try to find all the 'cards' with the same symbol on them.

"""
import random


def game_setup(rows, cols):
    board = []
    for row in range(rows):
        columns = []
        for each in range(cols):
            columns.append('.')
        board.append(columns)

    return board


# Creates the dotted board which will be first shown to the player.

def draw(b):
    for row in b:
        for char in row:
            print(char, end='')
        print()


# Actually draws the dotted board. o3o

def files(name):
    file = open(name, 'r')
    text = file.read()
    symbols = text.split()
    return symbols


# It's file reading time.

def hide_board(rows, cols, symbols):
    hidden_board = game_setup(rows, cols)
    for row in range(rows):
        for col in range(cols):
            hidden_board[row][col] = random.choice(symbols)

    return hidden_board


def get_guess(previous_guesses, board):
    guess = input("Enter position to guess: ")
    bound_checker = guess.split()
    while int(bound_checker[0]) > len(board) or int(bound_checker[1]) > len(board[0]):
        print("Out of bonds")
        guess = input("Try another input: ")
        bound_checker = guess.split()
    while guess in previous_guesses:
        guess = input("Try another input: ")
    return guess


def bounds(board, row, col):
    if row > len(board) or col > len(board[0]):
        print("Coordinates out of bound, please retry")
    elif board[row][col] != '.':
        print("Already guessed this coordinate, please retry.")


def count_letters(board):
    frequency_of_letters = [0] * 26
    for row in board:
        for char in row:
            index = ord(char) - 65
            frequency_of_letters[index] += 1
    return frequency_of_letters[0:26]
    # 0th index = as, 1st = bs, 2nd = cs, 3rd = ds


def period_counter(board):
    counter = 0
    for row in board:
        for char in row:
            if char == '.':
                counter += 1
    return counter


"""

Counts all the periods in the function.
"""


def undo(moves, board):
    for move in moves:
        m = move.split(" ")
        row, col = int(m[0]), int(m[1])
        board[row][col] = '.'
    return board


"""

Undos elements of the function.
"""


def check_win(hidden_board):
    for row in hidden_board:
        for col in row:
            if col == '.':
                return False
    return True


def letter_to_dot(board, user_guess):
    new_board = game_setup(len(board), len(board[0]))
    for row in range(len(board)):
        for column in range(len(board[row])):
            if board[row][column] == user_guess:
                new_board[row][column] = '.'
            else:
                new_board[row][column] = new_board[row][column]
    return new_board


def revealing(hidden_board, board, row, col):
    board[row][col] = hidden_board[row][col]
    return board


def board_counter(board):
    # make a dictionary of the contents of the grid
    board_dict = {}
    for row in board:
        for col in row:
            if col not in board:
                board_dict[col] = 1
            else:
                board_dict[col] += 1
    return board_dict


# noinspection PyTypeChecker
def main():
    row_col_seed = input("Enter Row, Col, Seed: ").split(", ")
    row = int(row_col_seed[0])
    col = int(row_col_seed[1])
    input_seed = int(row_col_seed[2])
    random.seed(input_seed)
    name = input("File name?")

    board = game_setup(row, col)
    symbols = files(name)
    hidden_board = hide_board(row, col, symbols)
    previous_guesses = []
    # make a deep copy of original_amounts
    frequency_of_letters = count_letters(hidden_board)

    draw(board)
    cur_char = None
    is_first = True
    game_start = True
    while game_start:
        this_turn = []
        # get user input !
        user_guess = get_guess(previous_guesses, board)

        this_turn.append(user_guess)
        previous_guesses.append(user_guess)
        user_guess = user_guess.split(" ")
        user_guess[0] = int(user_guess[0]) - 1
        user_guess[1] = int(user_guess[1]) - 1
        user_guessed_letter = hidden_board[user_guess[0]][user_guess[1]]
        found = 1
        # check if all the characters have been guessed and lock them in place
        if found == frequency_of_letters[ord(user_guessed_letter) - 65]:
            print("You have found all of the", user_guessed_letter)
            board[user_guess[0]][user_guess[1]] = hidden_board[user_guess[0]][user_guess[1]]
            is_first = True
            cur_char = None
        else:
            if is_first:
                cur_char = user_guessed_letter
                board = revealing(hidden_board, board, user_guess[0], user_guess[1])
                is_first = False
                frequency_of_letters[ord(user_guessed_letter) - 65] -= 1
                print("Enter a position that matches", user_guessed_letter, ", you have", frequency_of_letters[ord(user_guessed_letter) - 65], "left!")
            else:
                letter_to_dot(board, cur_char)
                cur_char = None
                is_first = True
        draw(board)

        # check if the user won
        win = check_win(board)
        if win:
            print("You win!")
            game_start = False


if __name__ == '__main__':
    main()
