let fs = require("fs")

const results = [];
const regex = /mul\((\d+),(\d+)\)/g;

let data = fs.readFileSync("./in.txt", { encoding: "utf-8" });
let match;
let ans = 0

// Use a while loop with regex.exec() to capture all matches
while ((match = regex.exec(data)) !== null) {
    results.push({ num1: parseInt(match[1]), num2: parseInt(match[2]) });
    ans = ans + (parseInt(match[1]) * parseInt(match[2]))
}

console.log(results);
console.log(ans); 