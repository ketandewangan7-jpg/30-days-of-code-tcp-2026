// select elements
let boxes = document.querySelectorAll(".box");
let resetBtn = document.querySelector("#reset-btn");
let newGameBtn = document.querySelector("#new-btn");
let msgContainer = document.querySelector(".msg-container");
let msg = document.querySelector("#msg");

// game variables
let turnO = true;   // true = O turn, false = X turn
let count = 0;     // count moves

// winning positions
const winPatterns = [
    [0, 1, 2],
    [0, 3, 6],
    [0, 4, 8],
    [1, 4, 7],
    [2, 5, 8],
    [2, 4, 6],
    [3, 4, 5],
    [6, 7, 8],
];

// draw function
const showDraw = () => {
    msg.innerText = "Game Draw";
    msgContainer.classList.remove("hide");
};

// click on box
boxes.forEach((box) => {
    box.addEventListener("click", () => {

        if (turnO === true) {
            box.innerText = "O";
            turnO = false;
        } else {
            box.innerText = "X";
            turnO = true;
        }

        box.disabled = true;
        count = count + 1;

        if (checkWinner() === true) {
            return;
        }

        if (count === 9) {
            showDraw();
        }
    });
});

// check winner
const checkWinner = () => {
    for (let i = 0; i < winPatterns.length; i++) {
        let pattern = winPatterns[i];

        let a = boxes[pattern[0]].innerText;
        let b = boxes[pattern[1]].innerText;
        let c = boxes[pattern[2]].innerText;

        if (a !== "" && a === b && b === c) {
            msg.innerText = "Winner is " + a;
            msgContainer.classList.remove("hide");
            disableBoxes();
            return true;
        }
    }
    return false;
};

// disable all boxes
const disableBoxes = () => {
    for (let box of boxes) {
        box.disabled = true;
    }
};

// enable all boxes
const enableBoxes = () => {
    for (let box of boxes) {
        box.innerText = "";
        box.disabled = false;
    }
};

// reset game
const resetGame = () => {
    turnO = true;
    count = 0;
    enableBoxes();
    msgContainer.classList.add("hide");
};

// buttons
newGameBtn.addEventListener("click", resetGame);
resetBtn.addEventListener("click", resetGame);
