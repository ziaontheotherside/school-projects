"""
File:         metro_lines.py
Author:       Zia Animashaun
Date:         5/12/2022
Section:      Section 13
E-mail:       fanimas1@umbc.edu
Description:  A program to create a trip planner which will tell a user how to get from one station to another.

"""

"""
I feel pretty proud of myself for this project for using a lot of stuff I learned from textbooks and videos.
The display actually seems to really match up and that's exciting! :
"""


def create_train(trains, id, line, position, lines):
    if line not in lines:
        print("This line does not exist!")
        return trains, lines

    if id not in trains:
        trains[id] = {
            "line": line,
            "current_station": position}
    return trains, lines


def create_station(station_name, stations):
    if station_name not in stations:
        stations[station_name] = {}
    else:
        print("Station", station_name, " already exists.")
    return stations


def connect_stations(station_1, station_2, line_name, stations, lines):
    """
    Connects two stations together! Click-click. ^^
    arguments 'n stuff:
        station_1: string (name of station)
        station_2: string (name of station)
        line_name: string (name of line)
        stations: dictionary (stations)
    """
    stations[station_1][station_2] = line_name
    stations[station_2][station_1] = line_name
    lines.append(line_name)
    return stations, lines


def driver(start, end, stations):
    visited = []
    solution = []
    plan_trip(start, end, stations, visited, solution)
    if len(solution) == 0:
        print("No path exists.")
        return

    current_min = solution[0]
    for soln in solution:
        if len(soln) < len(current_min):
            current_min = soln

    solution = current_min
    print(form_path(solution, stations))


def form_path(soln, stations):
    path = ''
    initial_line = None

    for i in range(len(soln) - 1):
        current_node = soln[i]
        next_node = soln[i + 1]
        current_line = stations[current_node][next_node]

        if initial_line is None:
            initial_line = current_line
            path += f"Start on the line {current_line} --> {current_node}"
        elif current_line != initial_line:
            path += f" --> At {current_node} transfer from the {initial_line} line to {current_line} line"
            initial_line = current_line
        else:
            path += f" --> {current_node}"
    path += f" --> {soln[-1]}"
    return path


def plan_trip(curr_node, end, stations, visited, solution):
    if curr_node == end:
        visited.append(curr_node)
        solution.append(visited.copy())
        visited.remove(curr_node)
    else:
        visited.append(curr_node)
        for neighbour in stations[curr_node]:
            if neighbour not in visited:
                plan_trip(neighbour, end, stations, visited, solution)
        visited.remove(curr_node)


def get_neighbours_on_line(station_name, line_name, stations):
    """
    Returns the neighbours of a station on a line. :3
    args:
        station_name: string (name of station)
        line_name: string (name of line upon the neighbours have to be searched)
        stations: dictionary (stations)
    returns:
        list of neighbours on the line
    """
    neighbours = []
    for neighbour, line in stations[station_name].items():
        if line == line_name:
            neighbours.append(neighbour)
    return neighbours
# Funny little thing but I have no clue whether there's a 'u' in the word neighbour or not, Google wasn't helpful.
# I think it's British and American differences yet again @_@


def step(stations, trains):
    for train in trains:
        step_train(train, trains, stations)


def step_train(train, trains, stations):
    """
    Moves a single train one step.
    args:
        train: string (id of train)
        trains: dictionary (trains)
        stations: dictionary (stations)
    """
    current_station = trains[train]["current_station"]
    line = trains[train]["line"]
    neighbours = get_neighbours_on_line(current_station, line, stations)

    # Case 0: Current station has no friends, a very lonely station.
    if len(neighbours) == 0:
        print(f'Train "{train}" is at station {current_station} and has no neighbours on line {line}.')

    # Case 1: Current station has only one friend, so basically on the end of the line. :)
    elif len(neighbours) == 1:
        next_station = neighbours[0]
        trains[train]["current_station"] = next_station
        trains[train]['prev_station'] = current_station
        print(f'Train "{train}" moved from {current_station} to {next_station}')

    # Case 2: Current station has 2 friends!
    else:
        neighbours = [n for n in neighbours if n != trains[train]['prev_station']]
        next_station = neighbours[0]
        trains[train]["current_station"] = next_station
        trains[train]['prev_station'] = current_station
        print(f'Train "{train}" moved from {current_station} to {next_station}')


def display_stations(stations):
    if len(stations) == 0:
        print("No stations exist! Sorry!")
        return
    for station in stations:
        print(station)
# Prints out all trains and their information.


def display_trains(trains):
    if len(trains) == 0:
        print("No trains exist.")
        return

    template = """*** Information for Train {train_id} ***
        Line: {line}
        Current Position: {curr_station}"""
    for train in trains:
        print(template.format(
            train_id=train,
            line=trains[train]["line"],
            curr_station=trains[train]["current_station"]))
# I'd like to thank the power of YouTube for teaching me something like this exists.


def get_station_info(stations, to_display):
    if to_display not in stations:
        print("Station does not exist.")
        return
    else:
        lines_of_stations = stations[to_display]
        print("Station Name: Station", to_display)
        print("The lines connected to this station are", lines_of_stations)
# Prints out information about a station.


def get_train_info(trains, train_id):
    if train_id not in trains:
        print("Train does not exist.")
        return
    else:
        print("Train: " + train_id)
        print("Line: " + trains[train_id]["line"])
        print("Current station: " + trains[train_id]["current_station"])
# Prints out information about a train.


def main():
    network = input(">>> ").strip()
# The main event, I guess!
    stations = {}
    trains = {}
    lines = []

    no_exit = True
    while no_exit:
        user_input = input(f"[{network}] >>>")
        if user_input == 'exit':
            no_exit = False
        elif user_input != 'exit':
            split_up = user_input.split()
            if split_up[0] == 'create':
                if split_up[1] == 'station':
                    station_name = split_up[2]
                    stations = create_station(station_name, stations)
                elif split_up[1] == 'train':
                    curr_pos = split_up[-1]
                    line_name = split_up[-2]
                    train_id = split_up[-3]
                    trains, lines = create_train(trains, train_id, line_name, curr_pos, lines)
            elif split_up[0] == 'connect':
                station_1 = split_up[2]
                station_2 = split_up[3]
                line_name = split_up[4]
                stations, lines = connect_stations(station_1, station_2, line_name, stations, lines)
            elif split_up[0] == 'plan':
                start, end = split_up[-2:]
                driver(start, end, stations)
            elif split_up[0] == 'step':
                step(stations, trains)
            elif split_up[0] == 'display':
                if split_up[1] == 'stations':
                    display_stations(stations)
                elif split_up[1] == 'trains':
                    display_trains(trains)
            elif split_up[0] == 'get':
                if split_up[1] == 'station':
                    station_name = split_up[-1]
                    get_station_info(stations, station_name)
                elif split_up[1] == 'train':
                    train_id = split_up[-1]
                    get_train_info(trains, train_id)
            else:
                print("Command not found, try again.")


if __name__ == "__main__":
    main()

