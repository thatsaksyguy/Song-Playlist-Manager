# Name:         Jonathan Chan
# OSU Email:    chanjon@oregonstate.edu
# Course:       CS361 - Software Engineering I
# Assignment:   Assignment 8
# Due Date:     10/31/2022
# Description:  A microservice that receives a playlist & command from a text 
#               file. Depending on the command, the microservice will either
#               shuffle or alphabetically sort the playlist.
import time
import random

# configurations
input_playlist = 'songs.txt'

# receives command to either shuffle or sort
# replaced with either shuffled or sorted playlist
output = 'order.txt'
# output ='fakefile.txt'

# list for holding the contents of the initial playlist
initial_order = list()
song_quantity = 0
new_order_command = ''


def get_valid_command():
    """
    Checks for a new order command in the output file. It confirms
    the command as either 'shuffle' or 'sort', no new valid command,
    or if there was an issue opening the text file.

    :return: True, String - a valid command & the command itself
    :return: False, String - an invalid command & command reset
    :return: False, String - an invalid command & file open failure
    """
    try:
        # get the new order command from the text file
        with open(output) as file:
            new_order_command = file.readline()
            
        new_order_command.strip()  # removes new line character

        if new_order_command == 'shuffle':
            return True, new_order_command
        elif new_order_command == 'sort':
            return True, new_order_command
        else:
            # reset new order command
            new_order_command = ''
            return False, new_order_command
    except:
        issue_message = 'Issue with opening output file.'
        return False, issue_message


def get_current_playlist():
    """
    Retrieves the current playlist in the initial playlist file.
    Updates the song quantity.

    :return: int, list of strings - a tuple of the number of songs
                                    & a list where each index = 1 song data
    """
    # reset song quantity and initial order
    song_quantity = 0
    initial_order = list()

    # build initial input playlist as a list
    with open(input_playlist) as file:
        for song in file:
            # song_quantity += 1
            initial_order.append(song.strip())

    song_quantity = len(initial_order)
    return song_quantity, initial_order


def my_shuffle(song_playlist):
    """
    Generate a new shuffled playlist.

    :song_playlist: list of strings - initial playlist to shuffle
    :return: list of strings - each index contains data for one song
    """
    new_shuffled_playlist = song_playlist.copy()
    random.shuffle(new_shuffled_playlist)
    return new_shuffled_playlist


def my_sort(song_playlist):
    """
    Generate a new sorted playlist by sorting alphabetically and
    ignores case of each song entry.

    :song_playlist: list of strings - initial playlist to sort
    :return: list of strings - each index contains data for one song
    """
    new_sorted_playlist = sorted(song_playlist, key=str.lower)
    return new_sorted_playlist


def update_text_file(song_playlist):
    """
    Writes the provided song playlist into the output text file

    :song_playlist: list of strings - playlist to write into text file
    """
    with open(output, 'w') as file:
        for song in song_playlist:
            file.write(song)
            file.write('\n')


def microservice():
    """
    Microservice for either shuffling or sorting a music playlist.
    """
    # finish = False
    # while not finish:
    while True:

        results, my_command = get_valid_command()
        # print('received a valid command:', str(results))

        if results:
            song_num, init_playlist = get_current_playlist()

            if my_command == 'shuffle':
                new_order = my_shuffle(init_playlist)

            # command to sort
            else:
                new_order = my_sort(init_playlist)

            update_text_file(new_order)
            # finish = True
            new_order_command = ''
        
        time.sleep(3)


if __name__ == '__main__':

    # test if method works for both and properly fails for fake text file
    # results, my_command = get_valid_command()

    # print('the results are:', str(results))
    # print('the command is', my_command)


    # test getting all songs from text file
    # song_num, my_order = get_current_playlist()
    # print('\nthere are', str(song_num), 'songs in the playlist')
    # print('the order is:\n')
    # for song in my_order:
    #     print(song)

    
    # test for sorting alphabetically the playlist
    # new_order1 = my_sort(my_order)
    # print('the new sorted order is:\n')
    # for song in new_order1:
    #     print(song)


    # test placing sorted playlist into output file
    # update_text_file(new_order1)


    # test for shuffling the playlist
    # new_order2 = my_shuffle(my_order)
    # print('\nthe new shuffled order is:\n')
    # for song in new_order2:
    #     print(song)
    microservice()
