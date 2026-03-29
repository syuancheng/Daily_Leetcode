var isAnagram = function(s, t) {
    if (s.length !== t.length) {
        return false;
    }

    // 箭头函数语法：const 函数名 = 参数 => 返回值
    // 只有一个参数时括号可以省略，只有一行返回值时 {} 和 return 可以省略
    // 对应普通函数：function idx(ch) { return ch.charCodeAt(0) - 'a'.charCodeAt(0) }
    const idx = ch => ch.charCodeAt(0) - 'a'.charCodeAt(0);
    // charCodeAt(0) 获取字符的 ASCII 码，0 表示取第一个字符
    // 对应 C++ 的 ch - 'a'

    const arr = new Array(26).fill(0);

    // 循环体只有一行时可以省略 {}，和 C++ 一样
    for (const ch of s) arr[idx(ch)]++;

    for (const ch of t) {
        arr[idx(ch)]--;

        // 小于 0 说明 t 里有 s 没有的字符
        if (arr[idx(ch)] < 0) return false;
    }

    return true;
};

console.log(isAnagram("anagram", "nagaram")); // true
console.log(isAnagram("rat", "car"));         // false