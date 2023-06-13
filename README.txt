README:

**play the game on windows command prompt for optimal experience

This part is just to explain what I did for each challenge:

1. Add elemental types to the classes.
- I ripped off Pokemon, same multipliers, same types
- Fire, water, and grass types are the three I used for this

1b. Give advantages, like rock paper scissors, or like pokemon.

2. Add a random chance to do critical damage.
- A critical hit is a 5% chance for every entity, deals 2x damage
- There are no additional factors that increase the chances of a critical hit

3. Add a speed stat that helps determine which character goes first.
- There isn't anything that explicitly states which entity attacked first
- Attack order is shown by the messages; attacked first -> your attack shows up first in the dialog

4. Add a small random chance to dodge or miss. Have a speed stat on the class that will impact this.
- A dodge has a 2% chance of happening for all entities
- The dodge RNG gets rerolled however many times the defender's speed stat is (defender speed 10 -> 2% chance rolled 10 times)

5a. Add consumable items, do this by making a class for items with name, and healing/damage.
5b. Add an inventory to the character classes by making a vector attribute.

6a. Add the ability to fight multiple enemies, either one at a time or…
- Just like Pokemon, whenever an enemy is defeated, they will deploy another until their whole party is defeated.

6b. Allow all enemies to attack the player but let the player pick which enemy to attack.
- Not really possible for my game since it's a 1-on-1 battle

7a. Add a party system that allows the player to switch which character is fighting.

7b. Let all allies attack enemies each turn.
- Sounded like too much work to implement, doesn't really work with how my game is structured anyways 


