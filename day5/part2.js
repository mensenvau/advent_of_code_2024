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
    for (let i = 0; i < arr.length; i++) {
        arr[i] = { val: arr[i], order: 0 };
    }

    let is_check = true;
    for (let i = 0; i < arr.length; i++) {
        let idx = i;
        for (let j = 0; j < i; j++) {
            if (mp.get(arr[i].val) && mp.get(arr[i].val).has(arr[j].val)) {
                idx = Math.min(idx, j);
                is_check = false;
            }
        }

        let temp = arr[i];
        arr[i] = arr[idx];
        arr[idx] = temp;
        i = idx;
    }

    let sorted = arr.sort((a, b) => a.order - b.order);
    if (!is_check) {
        let mid_index = Math.floor(arr.length / 2);
        sum = sum + parseInt(sorted[mid_index].val);
    }
}

console.log(sum)