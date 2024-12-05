let fs = require("fs");

let data = fs.readFileSync("./in.txt", { encoding: "utf-8" });
let rules = data.split("\n\n")[0].split("\n");
let x, y;

let mp = new Map();
for (let item of rules) {
    x = item.split("|")[0];
    y = item.split("|")[1];
    if (!mp.has(x)) mp.set(x, new Set());
    mp.get(x).add(y);
}

let update = data.split("\n\n")[1].split("\n");

let sum = 0;

for (let item of update) {
    let arr = item.split(",");
    let is_check = true;
    for (let i = 0; i < arr.length; i++) {
        for (let j = 0; j < i; j++) {
            if (mp.get(arr[i]) && mp.get(arr[i]).has(arr[j])) is_check = false;
        }
    }

    if (is_check) {
        let mid_index = Math.floor(arr.length / 2);
        sum = sum + parseInt(arr[mid_index]);
    }
}

console.log(sum)