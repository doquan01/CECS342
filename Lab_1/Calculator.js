const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

rl.question("", function (answer) {
    str = answer.replace(/'/g, "")
    arry = str.split(" ")
    
    a = 0

    if(arry[1] == "+"){
        a = parseInt(arry[0], 10) + parseInt(arry[2], 10)
        console.log(`${str} = ${a}`)
    }
    else if(arry[1] == "-"){
        a = parseInt(arry[0], 10) - parseInt(arry[2], 10)
        console.log(`${str} = ${a}`)
    }
    else if(arry[1] == "*"){
        a = parseInt(arry[0], 10) * parseInt(arry[2], 10)
        console.log(`${str} = ${a}`)
    }
    else if(arry[1] == "/"){
        a = Math.floor(parseInt(arry[0], 10) / parseInt(arry[2], 10))
        console.log(`${str} = ${a}`)
    }
  rl.close();
});