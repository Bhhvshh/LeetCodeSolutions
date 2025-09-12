import pandas as pd

def invalid_tweets(t: pd.DataFrame) -> pd.DataFrame:
    t = t[t["content"].str.len()>15]
    return t[["tweet_id"]]
    