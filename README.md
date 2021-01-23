# cplgr
**cplgr** is a text processor for texts in polytonic Greek.\
**CAUTION: this is a work in progress.**

## plgrconv
```
$ echo ">anthr^opos" | plgrconv
ἄνθρωπος
```

## plgrcoll
```
$ cat alpha.txt | plgrconv | plgrcoll
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
