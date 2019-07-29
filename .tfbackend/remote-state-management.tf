provider "aws" {
  version = "~> 2.6"
  region  = "us-east-2"
  profile = "your_aws_profile_name"
}

variable project_name {
  default = "monorepo-reason-app"
}

resource "aws_s3_bucket" "terraform-state-s3-store" {
  bucket = "${var.project_name}-tfstate"

  versioning {
    enabled = true
  }

  lifecycle {
    prevent_destroy = true
  }

  tags {
    Name    = "S3 Remote Terraform State Store"
    project = "${var.project_name}"
    env     = "development"
  }
}

resource "aws_s3_bucket_public_access_block" "terraform-state-s3-store-access-policy" {
  bucket = "${aws_s3_bucket.terraform-state-s3-store.id}"

  block_public_acls       = true
  block_public_policy     = true
  restrict_public_buckets = true
  ignore_public_acls      = true
}

resource "aws_dynamodb_table" "terraform-state-dynamodb-lock" {
  name         = "${var.project_name}-terraform-state-lock"
  billing_mode = "PAY_PER_REQUEST"
  hash_key     = "LockID"

  attribute {
    name = "LockID"
    type = "S"
  }

  tags {
    Name    = "DynamoDB Terraform State Lock Table"
    project = "${var.project_name}"
    env     = "development"
  }
}
