#[cfg(test)]
mod test {
    use rust::wc::count_lines;

    #[test]
    fn test_count_lines() {
        let s1 = String::from("");
        assert_eq!(count_lines(&s1), 0)
    }
}
