// https://www.codewars.com/kata/529bf0e9bdf7657179000008/solutions/javascript
function validSolution(board) {
  const data = {
    rows: {
      0: [],
      1: [],
      2: [],
      3: [],
      4: [],
      5: [],
      6: [],
      7: [],
      8: [],
    },
    cols: {
      0: [],
      1: [],
      2: [],
      3: [],
      4: [],
      5: [],
      6: [],
      7: [],
      8: [],
    },
    blocks: {
      0: [],
      1: [],
      2: [],
      3: [],
      4: [],
      5: [],
      6: [],
      7: [],
      8: [],
    },
  };
  for (let i = 0; i < 9; i++) {
    for (let j = 0; j < 9; j++) {
      elem = board[i][j];
      if (elem < 1 && elem > 9) return false;
      if (data.rows[i].indexOf(elem) != -1) return false;
      if (data.cols[j].indexOf(elem) != -1) return false;
      if (data.blocks[~~(i / 3) * 3 + ~~(j / 3)].indexOf(elem) != -1)
        return false;
      data.rows[i].push(elem);
      data.cols[j].push(elem);
      data.blocks[~~(i / 3) * 3 + ~~(j / 3)].push(elem);
    }
  }
  return true;
}

console.log(
  validSolution([
    [5, 3, 4, 6, 7, 8, 9, 1, 2],
    [6, 7, 2, 1, 9, 5, 3, 4, 8],
    [1, 9, 8, 3, 4, 2, 5, 6, 7],
    [8, 5, 9, 7, 6, 1, 4, 2, 3],
    [4, 2, 6, 8, 5, 3, 7, 9, 1],
    [7, 1, 3, 9, 2, 4, 8, 5, 6],
    [9, 6, 1, 5, 3, 7, 2, 8, 4],
    [2, 8, 7, 4, 1, 9, 6, 3, 5],
    [3, 4, 5, 2, 8, 6, 1, 7, 9],
  ])
);

console.log(
  validSolution([
    [5, 3, 4, 6, 7, 8, 9, 1, 2],
    [6, 7, 2, 1, 9, 5, 3, 4, 8],
    [1, 9, 8, 3, 4, 2, 5, 6, 7],
    [8, 5, 9, 7, 6, 1, 4, 2, 3],
    [4, 2, 6, 8, 5, 3, 7, 9, 1],
    [7, 1, 3, 9, 2, 4, 8, 5, 6],
    [9, 6, 1, 5, 3, 7, 2, 8, 4],
    [2, 8, 7, 4, 1, 9, 6, 3, 5],
    [3, 4, 5, 2, 8, 6, 1, 7, 9],
  ])
);
