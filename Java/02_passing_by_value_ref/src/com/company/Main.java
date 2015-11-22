package com.company;

public class Main {

    public static void Receiving(int var)
    {
        var = var + 2;
    }

    public static void changeLocalNome(Person p)
    {
        p.setName("Bilber");
    }

    public static void main(String[] args) {
	    int passing = 3;

        Receiving(passing);
        System.out.printf("The value of passing is: %d%n", passing);

        String name = "Nelson";
        Person p = new Person (name);
        System.out.println("Person name : " + p.getName());
        p.setName("Rodrigues");
        System.out.println("Person name : " + p.getName());

        /* So, objects are not passed by reference in Java. Let’s be a little bit more specific
        by what we mean here: objects are passed by reference – meaning that a reference/memory
        address is passed when an object is assigned to another – BUT (and this is what’s important)
        that reference is actually passed by value. The reference is passed by value because a copy
        of the reference value is created and passed into*/

        changeLocalNome(p);
        System.out.println("Person name : " + p.getName());

    }
}
