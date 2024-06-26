const f = function(s) {
    return Array.from(document.querySelectorAll(s));
};

let [p, inp, print, cap, low] = f("p, input, .print, .capitalize, .lower");

print.addEventListener("click", function() {
    p.textContent = inp.value;
});

cap.addEventListener("click", function() {
    p.textContent = inp.value.toUpperCase();
});

low.addEventListener("click", function() {
    p.textContent = inp.value.toLowerCase();
});
