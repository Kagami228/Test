var button_obj= document.getElementsByClassName("button");

color_object1 = [
    "red", "limegreen", "deeppink", "olive", "orangered", "darkcyan",
    "orange", "aqua", "gold", "yellow", "lightcyan", "khaki", 
    "cadetblue", "violet","blue","mediumorchid","rosybrown","black"];

function dublcl(el){
    var col = prompt('введите цвет который хотите видеть', 'red');
    el.style.color="black"
    for(var k=0;k<8;k++){
        var b=button_obj[k].style.backgroundColor;
        if(col==b){
            colorChanger(button_obj[k]);
        }
    }
    if(col=="black"){
        el.style.color="white"
    }
    el.style.backgroundColor=col;
    el.textContent=col;
    alert('Вы установили '+col+' цвет');
}
function colorChanger(el){
    el.textContent="";
    i=Math.floor(Math.random() * (18));
    for(var k=0;k<8;k++){
        var b=button_obj[k].style.backgroundColor;
        if(color_object1[i]==b){
            colorChanger(button_obj[k]);
            el.style.backgroundColor = color_object1[i];
            k=8;
        }
    }
    if(el.style.backgroundColor==color_object1[i]){
        colorChanger(el)
    }
    el.style.backgroundColor = color_object1[i];
}

window.onload = function() {
    for(var i=0;i<8;i++){
     colorChanger(button_obj[i]);
    }
};
