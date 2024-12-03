let fs = require("fs");

const regex = /(do\(\)|don't\(\)|mul\((\d+),(\d+)\))/g;

let data = fs.readFileSync("./in.txt", { encoding: "utf-8" });
let match;
let ans = 0;
let mulEnabled = true;

while ((match = regex.exec(data)) !== null) {
    const instruction = match[1];

    if (instruction === "do()") {
        mulEnabled = true;
    } else if (instruction === "don't()") {
        mulEnabled = false;
    } else if (instruction.startsWith("mul(")) {
        const num1 = parseInt(match[2]);
        const num2 = parseInt(match[3]);

        if (mulEnabled) {
            ans += num1 * num2;
        }
    }
}

console.log("Sum of enabled multiplications:", ans);
