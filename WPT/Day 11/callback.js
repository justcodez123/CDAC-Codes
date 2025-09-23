function call(callback){
    display();
}

function display(){
    setInterval(() => {console.log("Hello World")}, 2000)
}

call(display);