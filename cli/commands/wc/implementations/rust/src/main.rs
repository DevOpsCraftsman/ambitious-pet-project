use std::env;
use std::fs::File;
use std::io::{Error, Read};

fn main() -> std::io::Result<()> {
    let contents = get_content()?;
    wc_l(&contents);
    wc_w(&contents);
    wc_c(contents);
    Ok(())
}

fn wc_c(contents: String) {
    println!("{}", contents.len());
}

fn wc_w(contents: &String) {
    println!("{}", contents.split_whitespace().count());
}

fn wc_l(contents: &String) {
    println!("{}", contents.lines().count());
}

fn get_content() -> Result<String, Error> {
    let mut contents = String::new();
    let mut file = get_file()?;
    file.read_to_string(&mut contents)?;
    Ok(contents)
}

fn get_file() -> Result<File, Error> {
    let path = get_path();
    let file = File::open(path)?;
    Ok(file)
}

const DEFAULT_PATH: &'static str = "../../data/text.txt";

fn get_path() -> String {
    let args: Vec<String> = env::args().collect();
    let path_has_been_passed = args.len() > 1;
    let path = if path_has_been_passed {
        args[1].as_str()
    } else {
        DEFAULT_PATH
    };
    String::from(path)
}
