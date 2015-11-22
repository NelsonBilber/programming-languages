package com.company;


import java.util.HashMap;
import java.util.Map;

public class Main {

    public static void main(String[] args) {

        MapTester mt = new MapTester();
        Map<String, String> map = new HashMap<>();
        mt.generateData(map);

        map.forEach((k,v)-> System.out.printf("%s - %s\n", k,v));
    }
}
