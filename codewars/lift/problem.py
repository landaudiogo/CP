from functools import reduce
from collections import Counter

class Floor: 
    def __init__(self, floor_num, queue): 
        self.up = reduce(
            lambda acc, person: acc+1 if person > floor_num else acc,
            queue, 0
        )
        self.down = reduce(
            lambda acc, person: acc+1 if person < floor_num else acc,
            queue, 0
        )
        self.queue = list(queue)
        self.floor_num = floor_num

    def pop_down(self, space):
        if space == 0:
            return []
        idxs = []
        for i, person in enumerate(self.queue):
            if person < self.floor_num:
                idxs.append(i)
                if len(idxs) == space: 
                    break
        people = [
            self.queue.pop(idx)
            for idx in sorted(idxs, reverse=True)
        ]
        self.down -= len(people)
        return people
            
    def pop_up(self, space):
        if space == 0:
            return []

        idxs = []
        for i, person in enumerate(self.queue):
            if person > self.floor_num:
                idxs.append(i)
                if len(idxs) == space: 
                    break

        people = [
            self.queue.pop(idx)
            for idx in sorted(idxs, reverse=True)
        ]

        self.up -= len(people)
        return people


class Lift:
    def __init__(self, capacity, direction, current_position): 
        self.space = capacity
        self.direction = direction
        self.stops = [0]
        self.on_board = {}
        self.pos = current_position
        self.pointer = 0

    def remove_people(self, floor):
        self.space += self.on_board.pop(floor.floor_num, 0)

    def add_people(self, floor): 
        pop_func = floor.pop_up if self.direction == 1 else floor.pop_down
        people = pop_func(self.space)
        for person in people:
            self.on_board[person] = self.on_board.get(person, 0) + 1
        self.space -= len(people)

    def check_out(self, floor_num): 
        return True if self.on_board.get(floor_num, None) else False


class Dinglemouse(object):

    def __init__(self, queues, capacity):
        self.floors = [Floor(floor, queue) for floor, queue in enumerate(queues)]
        self.lift = Lift(capacity, 1, 0)
        self.lift.add_people(self.floors[0])
        
    def theLift(self):
        while True: 
            floor_num = self.next_stop()
            if floor_num == -1:
                if self.lift.stops[-1] != 0:
                    self.lift.stops.append(0)
                break
            if floor_num != self.lift.pos:
                self.lift.stops.append(floor_num)
            self.lift.pos = floor_num
            self.lift.remove_people(self.floors[floor_num])
            self.lift.add_people(self.floors[floor_num])

        return self.lift.stops 

    def next_stop(self): 
        [start, end, stride] = (
            [min(self.lift.pos+1, len(self.floors)-1), len(self.floors), 1] 
            if self.lift.direction else 
            [max(self.lift.pos-1, 0), -1, -1]
        )


        for floor_num in range(start, end, stride):
            if self.lift.check_out(floor_num):
                return floor_num
            if self.check_in(floor_num):
                return floor_num

        self.lift.direction = (self.lift.direction + 1) % 2
        [start, end, stride] = (
            [0, len(self.floors), 1]
            if self.lift.direction else
            [len(self.floors)-1, -1, -1]
        )
        for floor_num in range(start, end, stride):
            if self.lift.check_out(floor_num):
                return floor_num
            if self.check_in(floor_num):
                return floor_num

        self.lift.direction = (self.lift.direction + 1) % 2
        [start, end, stride] = (
            [0, len(self.floors), 1]
            if self.lift.direction else
            [len(self.floors)-1, -1, -1]
        )
        for floor_num in range(start, end, stride):
            if self.lift.check_out(floor_num):
                return floor_num
            if self.check_in(floor_num):
                return floor_num

        return -1

    def check_in(self, floor_num):
        if self.lift.direction:
            return self.floors[floor_num].up > 0
        else:
            return self.floors[floor_num].down > 0 


# Floors:    G     1      2        3     4      5      6         Answers:
tests = [
         [((3, 3, 3, 3, 3, 3), (), (), (), (), (), ()), 5]
]
  
for queues, capacity in tests:
    lift = Dinglemouse(queues, capacity)
    print(lift.theLift())

