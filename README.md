# bulls-and-cows
## 1. Description

See [Bulls and Cows - Wikipedia](https://en.wikipedia.org/wiki/Bulls_and_Cows).

You need to guess 4 different numbers, and every time when you guess, the game will report like: "?A?B".

The "A" means *bulls*, its digit is matching and the position is matching, too. And the "B" means *cows*, its digit is matching but the locations isn't.

## 2. How-to-play

Run the game with a compiler and a command-line.

And then, it'll output: `[1]>>`, means this is your first guess.

You can input a string contains 4 numbers (no spaces, tabs or other white character). But when you input wrong, you'll get these error message:

- Length Error: You must give 4 character
- Character Error: Every character must be number from 0 to 9
- Repeat Error: The characters must be different to another

Plus, you'll got some star symbol and a number at the random position for hint if you type `h` or `H` and hit Enter / return. It won't cost your chances.

Or, you'll get the correct result: `<< ?A?B`.

You only have 10 chances, if you guessed right, the congrats message will appear: 

> << You guessed right

And if you can't, another message will output:

> << You lost! The correct answer is: xxxx

---

Have fun!
