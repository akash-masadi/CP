document.addEventListener("keydown", function(event) {
    let p=document.querySelector("p");
    p.textContent="You pressed: "+event.key;
});
