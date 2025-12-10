function fibIter(n) {
    var a = 0, b = 1;
    for (var i = 0; i < n; i++) {
        var t = a + b;
        a = b;
        b = t;
    }
    return a;
}

WorkerScript.onMessage = function(message) {
    var result = fibIter(message.n);
    WorkerScript.sendMessage({ result: result });
}
