# cplgr
**cplgr** is a text processor for texts in polytonic Greek.\
**CAUTION: this is a work in progress.**

## cplgrconv
```
$ echo ">anthr^opos" | cplgrconv
ἄνθρωπος
```

## cplgrcoll
```
$ cat alpha.txt | cplgrconv | cplgrcoll
Πάντες
ἄνθρωποι
τοῦ
εἰδέναι
ὀρέγονται
φύσει
σημεῖον
δ'
...
```
