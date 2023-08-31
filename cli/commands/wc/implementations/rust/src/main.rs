use std::fs::File;
use std::io::Read;

fn main() -> std::io::Result<()> {
    let mut file = File::open("../../data/text.txt")?;
    let mut contents = String::new();
    file.read_to_string(&mut contents)?;
    println!("{}", contents.lines().count());
    println!("{}", contents.split_whitespace().count());
    println!("{}", contents.len());
    Ok(())
}
