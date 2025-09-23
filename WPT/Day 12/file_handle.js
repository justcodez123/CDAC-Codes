// File Handling

const f = require('fs');

f.writeFile('sample1.txt', "Aashish", (err) => {
    console.log(err);
});

f.close('sample1.txt');

// binary   synchrouns   internal Working 
// f.readFile("sample1.txt", "utf8", (err, data) => {
//     if (err) {
//         console.log("error occured " + err)
//     } else
//         console.log(data);
// })

// f.readFile()  /// Prmoise   async  