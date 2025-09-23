/* This(delay) async function uses promise to delay call function */
const delay = (time) => new Promise(
    (res) => setTimeout(res,time)
)

let i = 0;
async function call(callback){
    try{
        /* delay function is used to create delay in execution */        
        await delay(1000);
        console.log("Time interval of 1s");

        setInterval(callback,2000);

    }
    catch(error){
        console.error("An error occured:" + error);
    }
}

console.log(call(()=>{i+1; console.log(i+1 +" hello world")}));
